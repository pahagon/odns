#include <iostream>

#include <Sockets/Utility.h>
#include <Sockets/SocketHandler.h>

#include "UdpForwardSocket.h"
#include "UdpClientSocket.h"

namespace Odns {

    UdpForwardSocket::UdpForwardSocket(ISocketHandler& h) :UdpSocket(h), client(h) {}

    /**
     * TODO: Implemate ipv6 support
     */
    void
    UdpForwardSocket::OnRawData(const char *p,size_t l,struct sockaddr *sa_from,socklen_t sa_len) {
        if (sa_len == sizeof(struct sockaddr_in)) { // IPv4

            struct sockaddr_in sa;
            memcpy(&sa, sa_from, sa_len);
            ipaddr_t a;
            memcpy(&a, &sa.sin_addr, 4);
            std::string ip;
            Utility::l2ip(a, ip);

            // client = &UdpClientSocket(Handler(), sa_from);
            client.SetSaFrom(&sa);
            port_t port = 41900;
            if (client.Bind(port) == -1) {
                std::cout << "Erro open client_socket";
            }
            Handler().Add(&client);
            client.SendToBuf("10.2.0.1", 53, p, l);

            // UdpSocket server(MasterHandler());
            // server.Bind(port);
            // server.SendToBuf("10.2.0.1", 53, p, l);
            // Handler().Add(&server);
            // client->SendToBuf("10.2.0.1", 53, p, l);

            printf("Received (Server) %d bytes from: %s:%d\n", l, ip.c_str(), ntohs(sa.sin_port));
            printf("%s\n", static_cast<std::string>(p).substr(0, l).c_str());
        }
    }

} // namespace Odns