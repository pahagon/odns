#!/usr/bin/env ruby

# 10.2.0.1

require 'rubygems'
require 'eventmachine'

module DNSClient
  def receive_data(d)
    get_peername[2,6].unpack "nC4"
  end
end

EM.run do
  EM.open_datagram_socket("localhost", 9999, DNSClient)
end