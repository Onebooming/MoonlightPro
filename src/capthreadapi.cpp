#include "../include/capthreadapi.h"

namespace MoonLight {
    void CapThreadApi::start()
    {
        std::unique_lock<std::mutex> lck(mtx_);
        if(is_running_)
        {
            std::cout << "thread is already running." << std::endl;
            return;
        }
        is_running_ = true;
        thread_ = new std::thread(thread_callback_);
    }

    void CapThreadApi::stop()
    {
        std::unique_lock<std::mutex> lck(mtx_);
        if(!is_running_)
        {
            return;
        }
        is_running_ = false;
        cv_.notify_all();
        thread_->join();
        delete thread_;
        thread_ = nullptr;
    }

    void CapThreadApi::wait()
    {
        std::unique_lock<std::mutex> lck(mtx_);
        cv_.wait(lck, [this] { return !is_running_; });
    }

    void CapThreadApi::notify()
    {
        cv_.notify_all();
    }

    bool CapThreadApi::isRunning()
    {
        return is_running_;
    }
    
    void CapThreadApi::join()
    {
        if(thread_ != nullptr)
        {
            thread_->join();
        }
    }

    void CapThreadApi::detach()
    {
        if(thread_ != nullptr)
        {
            thread_->detach();
        }
    }

} // namespace MoonLight