/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-12 22:25:20
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-17 21:45:56
 * @FilePath: /MoonLightPro/src/server/mnserversocket.cpp
 * @Description: server socket apis
 */

#include "../../include/mnserversocket.h"
#include <iostream>

namespace MoonLight {
ServerSocket::ServerSocket(size_t thread_pool_size) : thread_pool(thread_pool_size) {
    create();
}

void ServerSocket::bindAndListen(const std::string& ip, int port) {
    bind(ip, port);
    listen();
    epoll.add(sockfd, EPOLLIN);
}

void ServerSocket::start() {
    acceptConnections();
}

void ServerSocket::setCallback(std::function<void(int)> callback) {
    this->callback = callback;
}

void ServerSocket::acceptConnections() {
    std::vector<epoll_event> events;
    while (true) {
        int num_events = epoll.wait(events, 10, -1);
        for (int i = 0; i < num_events; ++i) {
            if (events[i].data.fd == sockfd) {
                int client_sock = accept();
                epoll.add(client_sock, EPOLLIN);
            } else if (events[i].events & EPOLLIN) {
                int client_sock = events[i].data.fd;
                thread_pool.enqueue([this, client_sock] {
                    callback(client_sock);
                });
            }
        }
    }
}

void ServerSocket::handleClient(int client_sock) {
    std::vector<uint8_t> data = recvData(client_sock);
    if (!data.empty()) {
        std::cout << "Received: ";
        for (uint8_t byte : data) {
            std::cout << byte;
        }
        std::cout << std::endl;

        std::vector<uint8_t> response = { 'M', 'e', 's', 's', 'a', 'g', 'e', ' ', 'r', 'e', 'c', 'e', 'i', 'v', 'e', 'd' };
        sendResponse(client_sock, response);
    }
    ::close(client_sock);
}

std::vector<uint8_t> ServerSocket::recvData(int client_sock) {
    std::vector<uint8_t> buffer(1024);
    int bytes_received = ::recv(client_sock, buffer.data(), buffer.size(), 0);
    if (bytes_received == -1) {
        throw std::runtime_error("Failed to receive data");
    }
    buffer.resize(bytes_received);
    return buffer;
}

void ServerSocket::sendResponse(int client_sock, const std::vector<uint8_t>& data) {
    if (::send(client_sock, data.data(), data.size(), 0) == -1) {
        throw std::runtime_error("Failed to send response");
    }
}

}