#include <iostream>

#include <Sockets/Utility.h>
#include <Sockets/UdpSocket.h>

#include "UdpClientSocket.h"

namespace Odns {

    UdpClientSocket::UdpClientSocket(ISocketHandler& h) :UdpSocket(h) {
    }

    /**
    * TODO: Implemate ipv6 support
     */
    void
    UdpClientSocket::OnRawData(const char *p,size_t l,struct sockaddr *sa_from,socklen_t sa_len) {
        std::cout << "Receive server"; 

        // if (sa_len == sizeof(struct sockaddr_in)) { // IPv4
        //     struct sockaddr_in sa;
        //     memcpy(&sa, client_addr, sa_len);
        //     ipaddr_t a;
        //     memcpy(&a, &sa.sin_addr, 4);
        //     std::string ip;
        //     Utility::l2ip(a, ip);
        // 
        //     std::cout << "Receive in client";
        // 
        //     UdpSocket s(Handler());
        //     s.SendTo(ip, ntohs(sa.sin_port), p);
        // 
        //     // struct sockaddr_in sa;
        //     // memcpy(&sa, sa_from, sa_len);
        //     // ipaddr_t a;
        //     // memcpy(&a, &sa.sin_addr, 4);
        //     // std::string ip;
        //     // Utility::l2ip(a, ip);
        //     // printf("Received %d bytes from: %s:%d\n", l, ip.c_str(), ntohs(sa.sin_port));
        //     // printf("%s\n", static_cast<std::string>(p).substr(0, l).c_str());
        // }
    }

} // namespace Odns