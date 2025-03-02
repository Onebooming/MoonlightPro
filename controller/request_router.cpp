#include "include/request_router.h"

namespace MoonLight {
    RequestRouter::RequestRouter() {
        // 注册数据模型控制器
        dataControllers["UserInfo"] = std::make_shared<UserInfoDataController>();
    }

    std::pair<bool, shared_ptr<std::string>>  RequestRouter::checkSessionId(const MoonLight::Message &message) {
        std::pair<bool, shared_ptr<std::string>> result;
        if (!ValidateSession(message.session_id())) {
            // 返回鉴权失败响应
            shared_ptr<MoonLight::Message> response = make_shared<MoonLight::Message>();
            response->set_msg_id(message.msg_id());
            response->set_session_id(message.session_id());
            response->set_operation(moonlight::RESPONSE);
            response->set_data_type(moonlight::OTHER);
            response->set_data("Invalid session");
            std::string serializedResponse;
            response->SerializeToString(&serializedResponse);
            result.first = false;
            result.second = make_shared<std::string>(serializedResponse);
        }
        else {
            result.first = true;
            result.second = nullptr;
        }

        return result;
    }

    std::string RequestRouter::RouteRequest(const std::string& serializedRequest) {
        MoonLight::Message message;
        message.deserialize(serializedRequest);

        switch(message.operation()){
            case MoonLight::REGISTER:
                return handleRegister(message);
            case MoonLight::LOGIN:
                return handleLogin(message);
            default:
                // todo 校验session id
                if(checkSessionId(message).first == false){
                    return *checkSessionId(message).second;
                }

                // 根据data_type + operation调用相应的数据模型处理
                auto it = dataControllers.find(moonlight::DataType_Name(message.data_type()));
                if (it != dataControllers.end()) {
                    return it->second->ProcessAndResponse(message.data());
                }
                // 返回未知操作响应
                MoonLight::Message response;
                response.set_msg_id(message.msg_id());
                response.set_session_id(message.session_id());
                response.set_operation(moonlight::RESPONSE);
                response.set_data_type(moonlight::OTHER);
                response.set_data("Unknown operation");
                std::string serializedResponse;
                response.SerializeToString(&serializedResponse);
                return serializedResponse;
        }
    }

    std::string RequestRouter::handleRegister(const MoonLight::Message &message) {
        MoonLight::RegisterRequest registerData;
        registerData.ParseFromString(message.data());

        // 处理注册逻辑
        MNRedis *redis = MNRedis::GetInstance();
        bool bSucceed = redis->add(registerData.username(), registerData.password());

        MoonLight::RegisterResponse registerResponse;
        if(true == bSucceed)
        {
            registerResponse.set_success(true);
            registerResponse.set_message("Registration successful");
            registerResponse.set_session_id("newly_generated_session_id"); 
        }
        else
        {
            registerResponse.set_success(false);
            registerResponse.set_message("Registration failed");
            registerResponse.set_session_id("");
        }

        MoonLight::Message response;
        response.set_msg_id(message.msg_id());
        response.set_session_id(message.session_id());
        response.set_operation(MoonLight::RESPONSE);
        response.set_data_type(MoonLight::USER_INFO);

        std::string serializedData;
        registerResponse.SerializeToString(&serializedData);
        response.set_data(serializedData);

        std::string serializedResponse;
        response.SerializeToString(&serializedResponse);
        return serializedResponse;
    }

    std::string RequestRouter::handleLogin(const MoonLight::Message& message) {
        MoonLight::LoginRequest loginRequest;
        loginRequest.ParseFromString(message.data());

        // 处理登录逻辑，检查用户名和密码
        MNRedis* redis = MNRedis::GetInstance();
        std::string storedData = redis->get(loginRequest.username());
        MoonLight::RegisterRequest storedUser;
        storedUser.ParseFromString(storedData);

        moonlight::LoginResponse loginResponse;
        if (storedUser.password() == loginRequest.password()) {
            // 密码匹配，生成session id
            loginResponse.set_success(true);
            loginResponse.set_session_id("newly_generated_session_id");
            loginResponse.set_message("Login successful");
        } else {
            // 密码不匹配
            loginResponse.set_success(false);
            loginResponse.set_message("Invalid username or password");
        }

        MoonLight::Message response;
        response.set_msg_id(message.msg_id());
        response.set_session_id(message.session_id());
        response.set_operation(MoonLight::RESPONSE);
        response.set_data_type(MoonLight::USER_INFO);

        std::string serializedData;
        loginResponse.SerializeToString(&serializedData);
        response.set_data(serializedData);

        std::string serializedResponse;
        response.SerializeToString(&serializedResponse);
        return serializedResponse;
    }

    bool RequestRouter::ValidateSession(const std::string& sessionId) {
        // 校验session id的逻辑
        return true; // 默认返回true，实际实现时需要进行session id的校验
    }
}