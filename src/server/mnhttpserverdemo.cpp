/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:36:55
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 22:40:02
 * @FilePath: /MoonLightPro/src/server/mnhttpserverdemo.cpp
 * @Description: http server demo
 */
#include "../http/core/mnhttpserver.h"
#include "../http/app/app_hello.h"
#include "../http/app/app_admin_info.h"
#include "../../include/mnlog.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/ssl/context.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <iostream>

int main() {
    try {
        boost::asio::io_context ioc{1};
        boost::asio::ssl::context ctx{boost::asio::ssl::context::tlsv12};

        // 加载SSL证书
        ctx.use_certificate_chain_file("server.crt");
        ctx.use_private_key_file("server.key", boost::asio::ssl::context::pem);

        MoonLight::MNHttpServer server{ioc, ctx, 8080};
        MoonLight::HttpAppHello helloApp{server};
        MoonLight::HttpAppAdminInfo adminInfoApp{server};

        server.run();
        ioc.run();
    } catch (const std::exception& e) {
        MoonLight::MNLog::GetInstance()->LogMessage(MoonLight::MNLog::LogLevel::ERROR, "Exception: " + std::string(e.what()));
    }

    return 0;
}