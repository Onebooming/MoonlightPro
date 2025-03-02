#ifndef __MNEPOLL_H__
#define __MNEPOLL_H__

#include <sys/epoll.h>
#include <vector>
#include <unistd.h>
#include <stdexcept>

namespace MoonLight {
    class MNEpoll {
    public:
        MNEpoll();
        ~MNEpoll();

        void add(int fd, uint32_t events);
        void remove(int fd);
        void modify(int fd, uint32_t events);
        int wait(std::vector<epoll_event>& events, int max_events, int timeout);

    private:
        int epoll_fd;
    };
}

#endif // __MNEPOLL_H__