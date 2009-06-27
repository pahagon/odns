#!/usr/bin/env python
# -*- coding: utf-8 -*-

from twisted.internet.protocol import DatagramProtocol
from twisted.internet import reactor

class MulticastClientUDP(DatagramProtocol):

    def datagramReceived(self, datagram, (host, port)):
        print "received %r from %s:%d" % (datagram, host, port)
        # self.transport.write(datagram, (host, port))

# Send multicast on 224.0.0.1:8005, on our dynamically allocated port
reactor.listenUDP(0, MulticastClientUDP()).write('www.nuxlli.com.br',
                                                 ('10.2.0.1', 53))

reactor.run()
