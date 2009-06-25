C=g++
CFLAGS=-Wall
TARGETS=odns

objects = Odns.o Socket.o ServerSocket.o

targets: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

odns: main.cpp $(objects)
	$C $(CFLAGS) -o odns main.cpp $(objects)

Odns.o: Odns.cpp
	$C $(CFLAGS) -c Odns.cpp

Socket.o: Socket.cpp
	$C $(CFLAGS) -c Socket.cpp
	
ServerSocket.o: ServerSocket.cpp
	$C $(CFLAGS) -c ServerSocket.cpp