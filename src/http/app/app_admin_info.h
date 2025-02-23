/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 22:18:22
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 22:33:11
 * @FilePath: /MoonLightPro/src/http/app/app_admin_info.h
 * @Description: 处理 /moonlight/admin/info 请求
 */
#ifndef HTTP_APP_ADMIN_INFO_H
#define HTTP_APP_ADMIN_INFO_H

#include "../core/mnhttpserver.h"
#include "../../../include/mnjson.h"
#include <string>

namespace MoonLight {

class HttpAppAdminInfo {
public:
    HttpAppAdminInfo(MNHttpServer& server);
    void handleGetRequest(boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session);
    void handlePostRequest(boost::beast::http::request<boost::beast::http::string_body> req, std::shared_ptr<void> session);

private:
    MNHttpServer& server;
    MNJson adminInfo;
};

} // namespace MoonLight

#endif // HTTP_APP_ADMIN_INFO_H