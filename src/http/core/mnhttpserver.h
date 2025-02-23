#ifndef __MNHTTPSERVER_H__
#define __MNHTTPSERVER_H__

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/context.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/dispatch.hpp> // Ensure dispatch is included
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <vector>
#include <map>
#include <functional>

namespace MoonLight
{

    class Session : public std::enable_shared_from_this<Session>
    {
    public:
        Session(boost::asio::ip::tcp::socket socket, boost::asio::ssl::context &ctx,
                std::map<std::string, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)>> &routes)
            : stream_(std::move(socket), ctx), routes_(routes) {}

        void run();

        void onRun();

        void onHandshake(boost::beast::error_code ec);

        void doRead();

        void onRead(boost::beast::error_code ec, std::size_t);

        void sendNotFound();

        void onWrite(boost::beast::error_code ec, std::size_t bytes_transferred, bool close);

        void doClose();

        // 添加这个函数来返回 stream_ 的引用
        boost::asio::ssl::stream<boost::asio::ip::tcp::socket>& stream() {
            return stream_;
        }

    private:
        boost::asio::ssl::stream<boost::asio::ip::tcp::socket>
            stream_; // Corrected to use boost::asio::ssl::stream
        boost::beast::flat_buffer buffer_;
        boost::beast::http::request<boost::beast::http::string_body> req_;
        std::map<std::string, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)>> &routes_;
    };

    class MNHttpServer
    {
    public:
        MNHttpServer(boost::asio::io_context &ioc, boost::asio::ssl::context &ctx, int port);
        void run();
        void addRoute(const std::string &path, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)> handler);

    private:
        void doAccept();
        void onAccept(boost::beast::error_code ec, boost::asio::ip::tcp::socket socket);

        boost::asio::ip::tcp::acceptor acceptor_;
        boost::asio::ssl::context &ctx_;
        std::map<std::string, std::function<void(boost::beast::http::request<boost::beast::http::string_body>, std::shared_ptr<void>)>> routes_;
    };

}

#endif // __MNHTTPSERVER_H__