#include "mnhttpserver.h"
#include "../../../include/mnlog.h"
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/strand.hpp>
#include <boost/asio/dispatch.hpp> // Ensure dispatch is included
#include <boost/config.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>

namespace MoonLight {

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(boost::asio::ip::tcp::socket socket, boost::asio::ssl::context& ctx,
            std::map<std::string, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)>>& routes)
        : stream_(std::move(socket), ctx), routes_(routes) {}

    void run() {
        boost::asio::dispatch(stream_.get_executor(),
                              boost::beast::bind_front_handler(&Session::onRun, shared_from_this()));
    }

    void onRun() {
        stream_.async_handshake(boost::asio::ssl::stream_base::server,
                                boost::beast::bind_front_handler(&Session::onHandshake, shared_from_this()));
    }

    void onHandshake(boost::beast::error_code ec) {
        if (ec) {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Handshake failed: " + ec.message());
            return;
        }
        doRead();
    }

    void doRead() {
        req_ = {};
        boost::beast::http::async_read(stream_, buffer_, req_,
                                       boost::beast::bind_front_handler(&Session::onRead, shared_from_this()));
    }

    void onRead(boost::beast::error_code ec, std::size_t) {
        if (ec == boost::beast::http::error::end_of_stream) {
            return doClose();
        }

        if (ec) {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Read failed: " + ec.message());
            return;
        }

        auto it = routes_.find(req_.target().to_string());
        if (it != routes_.end()) {
            it->second(req_, shared_from_this());
        } else {
            sendNotFound();
        }
    }

    void sendNotFound() {
        auto const not_found = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
            boost::beast::http::status::not_found, req_.version());
        not_found->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
        not_found->set(boost::beast::http::field::content_type, "text/plain");
        not_found->body() = "The resource '" + std::string(req_.target()) + "' was not found.";
        not_found->prepare_payload();
        boost::beast::http::async_write(stream_, *not_found,
                                        boost::beast::bind_front_handler(&Session::onWrite, shared_from_this(), not_found->need_eof()));
    }

    void onWrite(bool close, boost::beast::error_code ec, std::size_t) {
        if (ec) {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Write failed: " + ec.message());
            return;
        }

        if (close) {
            return doClose();
        }

        doRead();
    }

    void doClose() {
        boost::beast::error_code ec;
        stream_.shutdown(ec);
        if (ec) {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Shutdown failed: " + ec.message());
        }
    }

private:
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream_; // Corrected to use boost::asio::ssl::stream
    boost::beast::flat_buffer buffer_;
    boost::beast::http::request<boost::beast::http::string_body> req_;
    std::map<std::string, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)>>& routes_;
};

MNHttpServer::MNHttpServer(boost::asio::io_context& ioc, boost::asio::ssl::context& ctx, int port)
    : acceptor_(ioc), ctx_(ctx) {
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(boost::asio::socket_base::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen(boost::asio::socket_base::max_listen_connections);
}

void MNHttpServer::run() {
    doAccept();
}

void MNHttpServer::addRoute(const std::string& path, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)> handler) {
    routes_[path] = handler;
}

void MNHttpServer::doAccept() {
    acceptor_.async_accept(
        boost::asio::make_strand(acceptor_.get_executor()),
        boost::beast::bind_front_handler(&MNHttpServer::onAccept, this));
}

void MNHttpServer::onAccept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket) {
    if (!ec) {
        std::make_shared<Session>(std::move(socket), ctx_, routes_)->run();
    }
    doAccept();
}

} // namespace MoonLight