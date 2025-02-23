/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:37:10
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 22:43:21
 * @FilePath: /MoonLightPro/src/client/mnhttpclientdemo.cpp
 * @Description: http client demo
 */
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    try {
        if (argc != 4 && argc != 5) {
            std::cerr << "Usage: " << argv[0] << " <host> <port> <target> [<body>]\n";
            return EXIT_FAILURE;
        }

        auto const host = argv[1];
        auto const port = argv[2];
        auto const target = argv[3];
        int version = 11;

        boost::asio::io_context ioc;
        boost::asio::ip::tcp::resolver resolver(ioc);
        boost::asio::ssl::context ctx(boost::asio::ssl::context::tlsv12_client);
        boost::asio::ssl::stream<boost::asio::ip::tcp::socket> stream(ioc, ctx);  // 使用 boost::asio::ssl::stream

        if (!SSL_set_tlsext_host_name(stream.native_handle(), host)) {
            boost::beast::error_code ec{static_cast<int>(::ERR_get_error()), boost::asio::error::get_ssl_category()};
            throw boost::beast::system_error{ec};
        }

        auto const results = resolver.resolve(host, port);
        boost::asio::connect(stream.next_layer(), results.begin(), results.end());
        stream.handshake(boost::asio::ssl::stream_base::client);

        boost::beast::http::request<boost::beast::http::string_body> req{boost::beast::http::verb::get, target, version};
        req.set(boost::beast::http::field::host, host);
        req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        if (argc == 5) {
            req.method(boost::beast::http::verb::post);
            req.body() = argv[4];
            req.prepare_payload();
        }

        boost::beast::http::write(stream, req);

        boost::beast::flat_buffer buffer;
        boost::beast::http::response<boost::beast::http::dynamic_body> res;
        boost::beast::http::read(stream, buffer, res);

        std::cout << res << std::endl;
        boost::beast::error_code ec;
        stream.shutdown(ec);
        if (ec == boost::asio::error::eof) {
            ec = {};
        }
        if (ec) {
            throw boost::beast::system_error{ec};
        }
    } catch (std::exception const& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}