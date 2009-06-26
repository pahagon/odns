#include <iostream>

#include <Sockets/Utility.h>
#include <Sockets/SocketHandler.h>

#include "UdpForwardSocket.h"

namespace Odns {

    UdpForwardSocket::UdpForwardSocket(ISocketHandler& h) :UdpSocket(h) {}
    
    void UdpForwardSocket::setClient(UdpClientSocket& c) {
        client = &c;
    }

    /**
     * TODO: Implemate ipv6 support
     */
    void
    UdpForwardSocket::OnRawData(const char *p,size_t l,struct sockaddr *sa_from,socklen_t sa_len) {
        if (sa_len == sizeof(struct sockaddr_in)) { // IPv4

            // port_t port = 41900;

            // if (client_socket->Bind(port) == -1) {
                // std::cout << "Erro open client_socket";
            // }
            // MasterHandler().Add(client_socket);
            // client_socket->SendTo("10.2.0.1", 53, p);
            
            // UdpSocket server(MasterHandler());
            // server.Bind(port);
            // server.SendToBuf("10.2.0.1", 53, p, l);
            // Handler().Add(&server);
            
            client->SendToBuf("10.2.0.1", 53, p, l);

            struct sockaddr_in sa;
            memcpy(&sa, sa_from, sa_len);
            ipaddr_t a;
            memcpy(&a, &sa.sin_addr, 4);
            std::string ip;
            Utility::l2ip(a, ip);
            printf("Received %d bytes from: %s:%d\n", l, ip.c_str(), ntohs(sa.sin_port));
            printf("%s\n", static_cast<std::string>(p).substr(0, l).c_str());
        }
    }

} // namespace Odns