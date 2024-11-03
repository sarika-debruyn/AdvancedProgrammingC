CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -L../part1
LDLIBS = -lmylist

revecho: revecho.o

revecho.o: revecho.c
	$(CC) -c $(CFLAGS) -I../part1 -c revecho.c

.PHONY: clean

clean:
	rm -f *.o *~ revecho
