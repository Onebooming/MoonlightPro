#include "../include/mnepoll.h"

namespace MoonLight {
    MNEpoll::MNEpoll() {
        epoll_fd = epoll_create1(0);
        if (epoll_fd == -1) {
            throw std::runtime_error("Failed to create epoll file descriptor");
        }
    }

    MNEpoll::~MNEpoll() {
        close(epoll_fd);
    }

    void MNEpoll::add(int fd, uint32_t events) {
        epoll_event event;
        event.events = events;
        event.data.fd = fd;
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1) {
            throw std::runtime_error("Failed to add file descriptor to epoll");
        }
    }

    void MNEpoll::remove(int fd) {
        if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, nullptr) == -1) {
            throw std::runtime_error("Failed to remove file descriptor from epoll");
        }
    }

    void MNEpoll::modify(int fd, uint32_t events) {
        epoll_event event;
        event.events = events;
        event.data.fd = fd;
        if (epoll_ctl(epoll_fd, EPOLL_CTL_MOD, fd, &event) == -1) {
            throw std::runtime_error("Failed to modify file descriptor in epoll");
        }
    }

    int MNEpoll::wait(std::vector<epoll_event>& events, int max_events, int timeout) {
        events.resize(max_events);
        int num_events = epoll_wait(epoll_fd, events.data(), max_events, timeout);
        if (num_events == -1) {
            throw std::runtime_error("Failed to wait for events");
        }
        return num_events;
    }
}