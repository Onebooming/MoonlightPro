/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-17 21:39:24
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-17 21:40:44
 * @FilePath: /MoonLightPro/src/mnthreadpool.cpp
 * @Description: 线程池实现类
 */
#include "../include/mnthreadpool.h"

namespace MoonLight {
ThreadPool::ThreadPool(size_t num_threads) : stop(false) {
    for (size_t i = 0; i < num_threads; ++i) {
        workers.emplace_back(&ThreadPool::worker_thread, this);
    }
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    condition.notify_all();
    for (std::thread &worker : workers) {
        worker.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        if (stop) {
            throw std::runtime_error("enqueue on stopped ThreadPool");
        }
        tasks.push(std::move(task));
    }
    condition.notify_one();
}

void ThreadPool::worker_thread() {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            condition.wait(lock, [this] { return stop || !tasks.empty(); });
            if (stop && tasks.empty()) {
                return;
            }
            task = std::move(tasks.front());
            tasks.pop();
        }
        task();
    }
}
}