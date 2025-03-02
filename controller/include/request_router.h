/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-03-02 21:26:47
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-03-02 21:45:38
 * @FilePath: /MoonlightPro/controller/include/request_router.h
 * @Description: 请求路由器
 */
#ifndef __REQUEST_ROUTER_H__
#define __REQUEST_ROUTER_H__

#include "data_controller.h"
#include "../common/include/mnlog.h"
#include "../common/include/mnredis.h"
#include "../model/protc_cpps/message.pb.h"
#include "../model/protc_cpps/register.pb.h"
#include "../model/protc_cpps/login.pb.h"
#include <memory>
#include <string>
#include <unordered_map>

namespace MoonLight {
    class RequestRouter {
    public:
        RequestRouter();

        // 处理请求并返回响应
        std::string RouteRequest(const std::string& serializedRequest);

    private:
        // 注册处理函数
        std::string handleRegister(const MoonLight::Message &message);

        // 登录处理函数
        std::string handleLogin(const MoonLight::Message &message);

        // session校验器
        bool validateSession(const std::string& sessionId);

        // 数据控制器
        std::unordered_map<std::string, std::shared_ptr<DataController>> controllers;
    };
}

#endif // __REQUEST_ROUTER_H__