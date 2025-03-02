/*
 * @Author: Onebooming 1026781822@qq.com
 * @Date: 2025-02-12 22:16:04
 * @LastEditors: Onebooming 1026781822@qq.com
 * @LastEditTime: 2025-02-17 21:46:38
 * @FilePath: /MoonLightPro/include/mnclientsocket.h
 * @Description: client socket apis
 */
#ifndef __MNCLIENTSOCKET__
#define __MNCLIENTSOCKET__

#include "mnsocket.h"
#include <vector>
#include <cstdint>

namespace MoonLight {

class ClientSocket : public MoonLight::Socket {
public:
    ClientSocket();
    void connectToServer(const std::string& server_ip, int server_port);
    void sendData(const std::vector<uint8_t>& data);
    std::vector<uint8_t> receiveData();
};

}

#endif // __MNCLIENTSOCKET__