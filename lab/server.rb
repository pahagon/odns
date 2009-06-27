#!/usr/bin/env ruby

# 10.2.0.1

require 'rubygems'
require 'eventmachine'

module DNSClient
  def initialize data
    @data = data
  end
  
  def post_init
    send_datagram @data, "10.2.0.1", 53
  end

  def receive_data(d)
    puts "DNSClient: #{d}"
  end
end

module DNSForward
  def receive_data(data)
    puts get_peername[2,6].unpack("nC4")
    # puts "DNSForward: #{data}"
    # send_datagram data
  end
end

EM.run do
  EM.open_datagram_socket("localhost", 9999, DNSForward)
end