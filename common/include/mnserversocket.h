#ifndef __MNSERVERSOCKET__
#define __MNSERVERSOCKET__

#include "mnsocket.h"
#include "mnepoll.h"
#include "mnthreadpool.h"
#include <vector>
#include <thread>
#include <cstdint>

namespace MoonLight {
class ServerSocket : public MoonLight::Socket {
public:
    ServerSocket(size_t thread_pool_size = 4);
    void bindAndListen(const std::string& ip, int port);
    void start();

    void setCallback(std::function<void(int)> callback);

private:
    void acceptConnections();
    void handleClient(int client_sock);
    std::vector<uint8_t> recvData(int client_sock);
    void sendResponse(int client_sock, const std::vector<uint8_t>& data);

    MNEpoll epoll;
    std::function<void(int)> callback;
    ThreadPool thread_pool;
};
}
#endif // __MNSERVERSOCKET__