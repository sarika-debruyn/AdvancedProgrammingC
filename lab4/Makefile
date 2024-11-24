CC = gcc
CFLAGS = -g -Wall -I../../lab3/solutions/part1
LDFLAGS = -L../../lab3/solutions/part1
LDLIBS = -lmylist

mdb-lookup: mdb-lookup.o

mdb-lookup.o: mdb-lookup.c mdb.h

.PHONY: clean
clean:
	rm -f *.o *~ mdb-lookup

.PHONY: all
all: clean mdb-lookup
