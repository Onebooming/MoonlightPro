/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:17:03
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-23 12:08:32
 * @FilePath: /MoonLightPro/src/http/core/MNHttpServer.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "mnhttpserver.h"
#include "../../../include/mnlog.h"

namespace MoonLight
{
    void Session::run()
    {
        boost::asio::dispatch(stream_.get_executor(),
                              boost::beast::bind_front_handler(&Session::onRun, shared_from_this()));
    }

    void Session::onRun()
    {
        stream_.async_handshake(boost::asio::ssl::stream_base::server,
                                boost::beast::bind_front_handler(&Session::onHandshake, shared_from_this()));
    }

    void Session::onHandshake(boost::beast::error_code ec)
    {
        if (ec)
        {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Handshake failed: " + ec.message());
            return;
        }
        doRead();
    }

    void Session::doRead()
    {
        req_ = {};
        boost::beast::http::async_read(stream_, buffer_, req_,
                                       boost::beast::bind_front_handler(&Session::onRead, shared_from_this()));
    }

    void Session::onRead(boost::beast::error_code ec, std::size_t)
    {
        if (ec == boost::beast::http::error::end_of_stream)
        {
            return doClose();
        }

        if (ec)
        {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Read failed: " + ec.message());
            return;
        }

        auto it = routes_.find(req_.target().to_string());
        if (it != routes_.end())
        {
            it->second(req_, shared_from_this());
        }
        else
        {
            sendNotFound();
        }
    }

    void Session::sendNotFound()
    {
        auto const not_found = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
            boost::beast::http::status::not_found, req_.version());
        not_found->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
        not_found->set(boost::beast::http::field::content_type, "text/plain");
        not_found->body() = "The resource '" + std::string(req_.target()) + "' was not found.";
        not_found->prepare_payload();
        boost::beast::http::async_write(stream_, *not_found,
                                        boost::beast::bind_front_handler(&Session::onWrite, shared_from_this(), not_found->need_eof()));
    }

    void Session::onWrite(boost::beast::error_code ec, std::size_t bytes_transferred, bool close)
    {
        if (ec)
        {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Write failed: " + ec.message());
            return;
        }

        if (close)
        {
            return doClose();
        }

        doRead();
    }

    void Session::doClose()
    {
        boost::beast::error_code ec;
        stream_.shutdown(ec);
        if (ec)
        {
            MNLog::GetInstance()->LogMessage(MNLog::LogLevel::ERROR, "Shutdown failed: " + ec.message());
        }
    }

    MNHttpServer::MNHttpServer(boost::asio::io_context &ioc, boost::asio::ssl::context &ctx, int port)
        : acceptor_(ioc), ctx_(ctx)
    {
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(boost::asio::socket_base::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen(boost::asio::socket_base::max_listen_connections);
    }

    void MNHttpServer::run()
    {
        doAccept();
    }

    void MNHttpServer::addRoute(const std::string &path, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)> handler)
    {
        routes_[path] = handler;
    }

    void MNHttpServer::doAccept()
    {
        acceptor_.async_accept(
            boost::asio::make_strand(acceptor_.get_executor()),
            boost::beast::bind_front_handler(&MNHttpServer::onAccept, this));
    }

    void MNHttpServer::onAccept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket)
    {
        if (!ec)
        {
            std::make_shared<Session>(std::move(socket), ctx_, routes_)->run();
        }
        doAccept();
    }
} // namespace MoonLight