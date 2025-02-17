/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-12 22:30:03
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-17 21:49:31
 * @FilePath: /MoonLightPro/src/server/serverdome1.cpp
 * @Description: server demo   
 */
#include "../../include/mnserversocket.h"
#include <iostream>

void clientHandler(int client_sock) {
    std::thread::id thread_id = std::this_thread::get_id();
    char buffer[1024];
    int bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        std::string client_id(buffer + 10, buffer + bytes_received); // Extract client ID from the message
        std::cout << "Thread " << thread_id << " handling client ID: " << client_id << std::endl;

        std::string response = "Message received from client ID: " + client_id;
        send(client_sock, response.c_str(), response.size(), 0);
    }
    close(client_sock);
}

int main() {
    MoonLight::ServerSocket server(4); // 创建一个包含4个线程的线程池
    server.bindAndListen("127.0.0.1", 8080);
    server.setCallback(clientHandler);
    std::cout << "Server is listening on 127.0.0.1:8080..." << std::endl;
    server.start();
    return 0;
}