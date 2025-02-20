#ifndef __MNHTTPSERVER_H__
#define __MNHTTPSERVER_H__

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/context.hpp>
#include <boost/asio/strand.hpp>
#include <boost/config.hpp>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <map>

namespace MoonLight
{
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