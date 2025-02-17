/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-12 20:58:15
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-12 21:27:04
 * @FilePath: /MoonLightPro/include/capthreadapi.h
 * @Description: thread api
 */

#ifndef __CAPTHREADAPI__
#define __CAPTHREADAPI__

#include <iostream>
#include <thread>
#include <functional>
#include <memory>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <atomic>

// 线程类：封装了线程的创建、销毁、等待、线程函数等操作，允许用户自定义线程函数
namespace MoonLight {
class CapThreadApi
{
public:
    CapThreadApi() : is_running_(false) {}
    ~CapThreadApi()
    {
        if(is_running_)
        {
            stop();
        }
    }

    void start();

    void stop();

    void wait();

    void notify();

    bool isRunning();

    // 设置线程的回调函数 （支持任意参数）
    template <typename Function, typename... Args>
    void setCallback(Function&& func, Args&&... args)
    {
        std::lock_guard<std::mutex> lock(mtx_);
        thread_callback_ = std::bind(std::forward<Function>(func), std::forward<Args>(args)...);
    }

    void join();

    void detach();

private:
    std::thread *thread_;
    std::function<void()> thread_callback_;
    std::atomic<bool> is_running_;
    std::mutex mtx_;
    std::condition_variable cv_;
};
} // namespace MoonLight
#endif // __CAPTHREADAPI__