#include "../include/mnlog.h"

namespace MoonLight {
    MNLog* MNLog::instance = nullptr;

    MNLog::MNLog() {
        logFile.open(logFileName, std::ios::app);
    }

    MNLog* MNLog::GetInstance() {
        if (instance == nullptr) {
            instance = new MNLog();
        }
        return instance;
    }

    void MNLog::LogMessage(LogLevel level, const std::string& message) {
        std::lock_guard<std::mutex> lock(logMutex);
        logFile << getTimestamp() << " " << logLevelToString(level) << " " << message << std::endl;
    }

    MNLog::~MNLog() {
        logFile.close();
    }

    std::string MNLog::getTimestamp() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return buf;
    }

    std::string MNLog::logLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::WARN:
                return "WARN";
            case LogLevel::ERROR:
                return "ERROR";
            case LogLevel::FATAL:
                return "FATAL";
            default:
                return "UNKNOWN";
        }
    }
}