#ifndef __MNTHREADPOOL__
#define __MNTHREADPOOL__

#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <stdexcept>

namespace MoonLight {

class ThreadPool {
public:
public:
    ThreadPool(size_t num_threads);
    ~ThreadPool();

    void enqueue(std::function<void()> task);

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;

    void worker_thread();
};

}

#endif // __MNTHREADPOOL__