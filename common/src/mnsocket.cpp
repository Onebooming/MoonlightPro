#include "../include/mnsocket.h"

namespace MoonLight {
    Socket::Socket() {
        sockfd = -1;
    }

    Socket::~Socket() {
        close();
    }

    void Socket::close() {
        if (sockfd != -1) {
            ::close(sockfd);
            sockfd = -1;
        }
    }

    void Socket::create() {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            throw std::runtime_error("create socket failed");
        }
    }

    void Socket::bind(const std::string& ip, int port) {
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        if (::bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
            throw std::runtime_error("bind socket failed");
        }
    }

    void Socket::listen(int backlog) {
        if (::listen(sockfd, backlog) == -1) {
            throw std::runtime_error("listen socket failed");
        }
    }

    int Socket::accept() {
        struct sockaddr_in client_addr;
        socklen_t len = sizeof(client_addr);
        int client_sockfd = ::accept(sockfd, (struct sockaddr*)&client_addr, &len);
        if (client_sockfd == -1) {
            throw std::runtime_error("accept socket failed");
        }
        return client_sockfd;
    }

    void Socket::connect(const std::string& ip, int port) {
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        if (::connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
            throw std::runtime_error("connect socket failed");
        }
    }
} // namespace MoonLight