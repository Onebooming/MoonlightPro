#ifndef __MNSOCKET__
#define __MNSOCKET__

#include <string>
#include <stdexcept>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

namespace MoonLight {
class Socket {
public:
    Socket();
    virtual ~Socket();

    void close();

protected:
    int sockfd;
    struct sockaddr_in addr;

    void create();
    void bind(const std::string& ip, int port);
    void listen(int backlog = 5);
    int accept();
    void connect(const std::string& ip, int port);
};
}
    


#endif // __MNSOCKET__