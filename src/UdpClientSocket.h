#ifndef _CLIENTSOCKET_H
#define _CLIENTSOCKET_H

#include <Sockets/UdpSocket.h>

namespace Odns {
    class UdpClientSocket : public UdpSocket {
        public:
            UdpClientSocket(ISocketHandler&);
            
            void SetSaFrom(struct sockaddr_in *);
            void OnRawData(const char *,size_t,struct sockaddr *,socklen_t);
            
        private:
            struct sockaddr_in *sa_client;
    }; // UdpForwardSocket
} // namespace Odns

#endif