env = Environment()
env.BuildDir('build/', 'src/')

SOURCES = {
  'all': [
    'build/main.cc', 'build/Odns.cc', 'build/UdpForwardSocket.cc', 'build/UdpClientSocket.cc'
  ]
}

env.Program(target  = 'odns',
            source  = SOURCES["all"],
            CCFLAGS = '$CCFLAGS -Wall -g -O2 -MD `Sockets-config`',
            LIBS    = ['Sockets', 'pthread', 'ssl', 'crypto'])

env.Clean('all', ['build'])