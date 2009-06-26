#ifndef _CLIENTSOCKET_H
#define _CLIENTSOCKET_H

#include <Sockets/UdpSocket.h>

namespace Odns {
    class UdpClientSocket : public UdpSocket {
        public:
            UdpClientSocket(ISocketHandler&);
            
            void OnRawData(const char *,size_t,struct sockaddr *,socklen_t);
    }; // UdpForwardSocket
} // namespace Odns

#endif