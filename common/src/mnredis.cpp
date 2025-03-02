#include "../include/mnredis.h"

namespace MoonLight {
    std::unique_ptr<MNRedis> MNRedis::instance = nullptr;
    std::mutex MNRedis::mutex;

    MNRedis::MNRedis() {
        redisContext = nullptr;
    }

    MNRedis::~MNRedis() {
        if (redisContext != nullptr) {
            redisFree(redisContext);
        }
    }

    MNRedis* MNRedis::GetInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr) {
                instance.reset(new MNRedis());
            }
        }
        return instance.get();
    }

    bool MNRedis::init(const std::string& ip, int port, const std::string& dbname) {
        if (redisContext != nullptr) {
            redisFree(redisContext);
        }
        redisContext = redisConnect(ip.c_str(), port);
        if (redisContext == nullptr || redisContext->err) {
            return false;
        }
        if (!dbname.empty()) {
            dbName = dbname;
            redisCommand(redisContext, "SELECT %s", dbname.c_str());
        }
        return true;
    }

    bool MNRedis::add(const std::string& key, const std::string& value) {
        if (redisContext == nullptr) {
            return false;
        }
        redisReply *reply = (redisReply *)redisCommand(redisContext, "SETNX %s %s", key.c_str(), value.c_str());
        bool result = reply->integer == 1;
        freeReplyObject(reply);
        return result;
    }

    std::string MNRedis::get(const std::string& key) {
        if (redisContext == nullptr) {
            return "";
        }
        redisReply *reply = (redisReply *)redisCommand(redisContext, "GET %s", key.c_str());
        std::string result = reply->str;
        freeReplyObject(reply);
        return result;
    }

    bool MNRedis::del(const std::string& key) {
        if (redisContext == nullptr) {
            return false;
        }
        redisReply *reply = (redisReply *)redisCommand(redisContext, "DEL %s", key.c_str());
        bool result = reply->integer == 1;
        freeReplyObject(reply);
        return result;
    }

    bool MNRedis::update(const std::string& key, const std::string& value) {
        if (redisContext == nullptr) {
            return false;
        }
        redisReply *reply = (redisReply *)redisCommand(redisContext, "SET %s %s", key.c_str(), value.c_str());
        bool result = reply->type == REDIS_REPLY_STATUS;
        freeReplyObject(reply);
        return result;
    }

    
}