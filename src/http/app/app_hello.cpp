/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:18:08
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-23 12:03:30
 * @FilePath: /MoonLightPro/src/http/app/app_hello.cpp
 * @Description: 请求处理url为 /moonlight/hello 的请求
 */
#include "app_hello.h"
#include "../core/mnhttpserver.h" // 包含Session类定义

namespace MoonLight {

HttpAppHello::HttpAppHello(MNHttpServer& server) : server(server) {
    server.addRoute("/moonlight/hello", std::bind(&HttpAppHello::handleRequest, this, std::placeholders::_1, std::placeholders::_2));
}

void HttpAppHello::handleRequest(boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session) {
    auto res = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
        boost::beast::http::status::ok, req.version());
    res->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
    res->set(boost::beast::http::field::content_type, "text/plain");
    res->body() = "hello world.";
    res->prepare_payload();
    boost::beast::http::async_write(static_cast<Session*>(session.get())->stream(), *res,
                                    boost::beast::bind_front_handler(&Session::onWrite, static_cast<Session*>(session.get()), res->need_eof()));
}

} // namespace MoonLight