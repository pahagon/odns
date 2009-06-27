#!/usr/bin/env python
# -*- coding: utf-8 -*-

# 10.2.0.1

from twisted.internet.protocol import DatagramProtocol
from twisted.internet import reactor
# from dpkt.dns import DNS

class DNSClient(DatagramProtocol):
    
    def __init__(self, server, host, port):
        self.client_server = server
        self.client_host = host
        self.client_port = port
    
    def datagramReceived(self, datagram, (host, port)):
        print "received no DNSClient %r from %s:%d" % (datagram, host, port)
        self.client_server.transport.write(datagram, (self.client_host, self.client_port))

class DNSForward(DatagramProtocol):

    def datagramReceived(self, datagram, (host, port)):
        print "received no DNSForward %r from %s:%d" % (datagram, host, port)
        reactor.listenUDP(0, DNSClient(self, host, port)).write(datagram, ("192.168.254.254", 53))

reactor.listenUDP(53, DNSForward())
reactor.run()