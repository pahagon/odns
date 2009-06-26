#include <iostream>

#include <Sockets/SocketHandler.h>
#include <Sockets/StdoutLog.h>

#include "Odns.h"
#include "UdpForwardSocket.h"
#include "UdpClientSocket.h"

namespace Odns {

    // using namespace Internal;

    Odns::Odns() {
        std::cout << "Passou aqui";

        SocketHandler socket_handler;
        StdoutLog log;

        socket_handler.RegStdLog(&log);
        UdpForwardSocket socket(socket_handler);

        port_t port = 9999;

        if (socket.Bind(port, 10) == -1) {
            std::cout << "Exiting...\n";
        } else {
            std::cout << "Ready to receive on port " << port << "\n";
        }

        socket_handler.Add(&socket);
        socket_handler.Select(1,0);
        while (socket_handler.GetCount())
        {
            socket_handler.Select(1,0);
        }
    }

    Odns::~Odns() {
    }

} // namespace Odns