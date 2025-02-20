/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:17:48
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 22:32:52
 * @FilePath: /MoonLightPro/src/http/app/app_hello.h
 * @Description: 请求处理url为 /moonlight/hello 的请求
 */
#ifndef HTTP_APP_HELLO_H
#define HTTP_APP_HELLO_H

#include "../core/mnhttpserver.h"

namespace MoonLight {

class HttpAppHello {
public:
    HttpAppHello(MNHttpServer& server);
    void handleRequest(boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session);

private:
    MNHttpServer& server;
};

} // namespace MoonLight

#endif // HTTP_APP_HELLO_H