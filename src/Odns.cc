#include <iostream>

#include <Sockets/SocketHandler.h>
#include <Sockets/StdoutLog.h>

#include "Odns.h"
#include "UdpForwardSocket.h"
#include "UdpClientSocket.h"

namespace Odns {

    // using namespace Internal;

    Odns::Odns() {
        SocketHandler socket_handler;
        StdoutLog log;

        socket_handler.RegStdLog(&log);
        UdpForwardSocket forward(socket_handler);
        UdpClientSocket client(socket_handler);
        
        forward.setClient(client);

        port_t port = 9999, back_port = 2055;

        if (forward.Bind(port, 10) == -1) {
            std::cout << "Exiting...\n";
        } else {
            std::cout << "Ready to receive on port " << port << "\n";
        }
        
        if (client.Bind(back_port, 10) == -1) {
            std::cout << "Exiting...\n";
        } else {
            std::cout << "Ready to receive on port " << port << "\n";
        }

        socket_handler.Add(&forward);
        socket_handler.Add(&client);
        
        socket_handler.Select(2,0);
        while (socket_handler.GetCount())
        {
            socket_handler.Select(2,0);
        }
    }

    Odns::~Odns() {
    }

} // namespace Odns