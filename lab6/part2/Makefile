CC = gcc
CFLAGS = -g -Wall

http-client: http-client.o

http-client.o: http-client.c

.PHONY: clean

clean:
	rm -f *.o *~ a.out http-client

.PHONY: all

all: clean http-client
