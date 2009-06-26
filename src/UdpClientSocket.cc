#include <iostream>

#include <Sockets/Utility.h>
#include <Sockets/UdpSocket.h>

#include "UdpClientSocket.h"

namespace Odns {

    UdpClientSocket::UdpClientSocket(ISocketHandler& h) :UdpSocket(h) {
    }
    
    void UdpClientSocket::SetSaFrom(struct sockaddr_in *sa) {
        sa_client = sa;
    }

    /**
     * TODO: Implemate ipv6 support
     */
    void
    UdpClientSocket::OnRawData(const char *p,size_t l,struct sockaddr *sa_from,socklen_t sa_len) {
        if (sa_len == sizeof(struct sockaddr_in)) { // IPv4

            struct sockaddr_in sa;
            memcpy(&sa, sa_client, sa_len);
            ipaddr_t a;
            memcpy(&a, &sa.sin_addr, 4);
            std::string ip;
            Utility::l2ip(a, ip);

            SendToBuf(ip, sa.sin_port, p, l);
            printf("Received (Client), send for: %s", ip.c_str());
        }
    }
} // namespace Odns