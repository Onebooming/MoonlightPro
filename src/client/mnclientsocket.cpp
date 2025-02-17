/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-12 22:15:47
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-17 21:47:21
 * @FilePath: /MoonLightPro/src/client/mnclientsocket.cpp
 * @Description: client socket apis
 */
#include "../../include/mnclientsocket.h"

namespace MoonLight {
ClientSocket::ClientSocket() {
    create();
}

void ClientSocket::connectToServer(const std::string& server_ip, int server_port) {
    connect(server_ip, server_port);
}

void ClientSocket::sendData(const std::vector<uint8_t>& data) {
    if (::send(sockfd, data.data(), data.size(), 0) == -1) {
        throw std::runtime_error("Failed to send data");
    }
}

std::vector<uint8_t> ClientSocket::receiveData() {
    std::vector<uint8_t> buffer(1024);
    int bytes_received = ::recv(sockfd, buffer.data(), buffer.size(), 0);
    if (bytes_received == -1) {
        throw std::runtime_error("Failed to receive data");
    }
    buffer.resize(bytes_received);
    return buffer;
}

}