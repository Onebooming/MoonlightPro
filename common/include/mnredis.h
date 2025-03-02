#ifndef __MNREDIS_H__
#define __MNREDIS_H__

#include <string>
#include <hiredis/hiredis.h>
#include <memory>
#include <mutex>

namespace MoonLight {
    class MNRedis {
    public:
        // 获取单例模式
        static MNRedis* GetInstance();

        // 初始化Redis数据库
        bool init(const std::string& ip = "127.0.0.1", int port = 6379, const std::string& dbname = "server_default");

        // add
        bool add(const std::string& key, const std::string& value);

        // get
        std::string get(const std::string& key);

        // del
        bool del(const std::string& key);

        // set
        bool update(const std::string& key, const std::string& value);

    private:
        MNRedis();
        ~MNRedis();
        MNRedis(const MNRedis&) = delete;
        MNRedis& operator=(const MNRedis&) = delete;

        redisContext *redisContext;
        std::string dbName;
        static std::unique_ptr<MNRedis> instance;
        static std::mutex mutex;
    };
}

#endif // __MNREDIS_H__