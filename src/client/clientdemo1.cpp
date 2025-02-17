/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-12 22:31:14
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-17 21:48:31
 * @FilePath: /MoonLightPro/src/client/clientdemo1.cpp
 * @Description: client demo1
 */
#include "../../include/mnclientsocket.h"
#include <iostream>
#include <vector>
#include <thread>
#include <cstdlib>

void clientTask(int client_id) {
    try {
        MoonLight::ClientSocket client;
        client.connectToServer("127.0.0.1", 8080);

        std::vector<uint8_t> data = { 'C', 'l', 'i', 'e', 'n', 't', ' ', 'I', 'D', ':', ' ', static_cast<uint8_t>(client_id) };
        client.sendData(data);
        std::vector<uint8_t> response = client.receiveData();

        std::cout << "Response from server for client " << client_id << ": ";
        for (uint8_t byte : response) {
            std::cout << byte;
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error for client " << client_id << ": " << e.what() << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_clients>" << std::endl;
        return 1;
    }

    int num_clients = std::atoi(argv[1]);
    if (num_clients <= 0) {
        std::cerr << "The number of clients must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<std::thread> client_threads;

    for (int i = 0; i < num_clients; ++i) {
        client_threads.emplace_back(clientTask, i + 1);
    }

    for (auto& thread : client_threads) {
        thread.join();
    }

    return 0;
}