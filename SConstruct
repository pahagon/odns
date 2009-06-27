env = Environment()
env.BuildDir('build/', 'src/')

SOURCES = {
  'all': [
    'build/CipherTest.cc', 'build/Cipher.cc', 'build/base32.c'
    #'build/main.cc', 'build/Odns.cc', 'build/UdpForwardSocket.cc', 'build/UdpClientSocket.cc'
  ]
}

env.Program(target  = 'odns',
            source  = SOURCES["all"],
            CCFLAGS = '$CCFLAGS -Wall -g -O2 -MD `Sockets-config`',
            OBJS    = ['/usr/lib/randombytes.o'],
            LIBS    = ['Sockets', 'pthread', 'ssl', 'crypto', 'nacl'])

env.Clean('all', ['build'])
