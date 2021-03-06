#ifndef _FORWARDSOCKET_H
#define _FORWARDSOCKET_H

#include <Sockets/UdpSocket.h>
#include "UdpClientSocket.h"

namespace Odns {
    class UdpForwardSocket : public UdpSocket {
        public:
            UdpForwardSocket(ISocketHandler&);

            void OnRawData(const char *,size_t,struct sockaddr *,socklen_t);
            
        private:
            
            UdpClientSocket client;
    }; // UdpForwardSocket
} // namespace Odns

#endif