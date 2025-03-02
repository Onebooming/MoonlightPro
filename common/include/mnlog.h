/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-20 21:47:03
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-20 21:51:44
 * @FilePath: /MoonLightPro/include/mnlog.h
 * @Description: 日志 API
 */
#ifndef MNLOG_H
#define MNLOG_H

#include <string>
#include <fstream>
#include <iostream>
#include <mutex>

namespace MoonLight {
    class MNLog {
    public:
        enum class LogLevel
        {
            INFO,
            DEBUG,
            WARN,
            ERROR,
            FATAL
        };
        static MNLog* GetInstance();
        void LogMessage(LogLevel level, const std::string& message);
        ~MNLog();
    private:
        MNLog();
        static MNLog* instance;
        std::ofstream logFile;
        std::mutex logMutex;
        const std::string logFileName = "moonlight.log";
        std::string getTimestamp();
        std::string logLevelToString(LogLevel level);

    };
}

#endif // MNLOG_H