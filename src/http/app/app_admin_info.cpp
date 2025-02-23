/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:18:39
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-23 12:07:10
 * @FilePath: /MoonLightPro/src/http/app/app_admin_info.cpp
 * @Description: 处理 /moonlight/admininfo 请求
 */

#include "app_admin_info.h"

namespace MoonLight {

HttpAppAdminInfo::HttpAppAdminInfo(MNHttpServer& server) : server(server) {
    server.addRoute("/moonlight/admininfo", [this](boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session) {
        if (req.method() == boost::beast::http::verb::get) {
            handleGetRequest(req, session);
        } else if (req.method() == boost::beast::http::verb::post) {
            handlePostRequest(req, session);
        } else {
            auto res = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
                boost::beast::http::status::bad_request, req.version());
            res->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
            res->set(boost::beast::http::field::content_type, "text/plain");
            res->body() = "Unsupported method";
            res->prepare_payload();
            boost::beast::http::async_write(static_cast<Session*>(session.get())->stream(), *res,
                                            boost::beast::bind_front_handler(&Session::onWrite, static_cast<Session*>(session.get()), res->need_eof()));
        }
    });
}

void HttpAppAdminInfo::handleGetRequest(boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session) {
    auto res = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
        boost::beast::http::status::ok, req.version());
    res->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
    res->set(boost::beast::http::field::content_type, "application/json");
    res->body() = adminInfo.toJsonString();
    res->prepare_payload();
    boost::beast::http::async_write(static_cast<Session*>(session.get())->stream(), *res,
                                    boost::beast::bind_front_handler(&Session::onWrite, static_cast<Session*>(session.get()), res->need_eof()));
}

void HttpAppAdminInfo::handlePostRequest(boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session) {
    if (adminInfo.fromJsonString(req.body())) {
        auto res = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
            boost::beast::http::status::ok, req.version());
        res->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
        res->set(boost::beast::http::field::content_type, "text/plain");
        res->body() = "Admin info updated";
        res->prepare_payload();
        boost::beast::http::async_write(static_cast<Session*>(session.get())->stream(), *res,
                                        boost::beast::bind_front_handler(&Session::onWrite, static_cast<Session*>(session.get()), res->need_eof()));
    } else {
        auto res = std::make_shared<boost::beast::http::response<boost::beast::http::string_body>>(
            boost::beast::http::status::bad_request, req.version());
        res->set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
        res->set(boost::beast::http::field::content_type, "text/plain");
        res->body() = "Invalid JSON";
        res->prepare_payload();
        boost::beast::http::async_write(static_cast<Session*>(session.get())->stream(), *res,
                                        boost::beast::bind_front_handler(&Session::onWrite, static_cast<Session*>(session.get()), res->need_eof()));
    }
}

} // namespace MoonLight