CC = gcc
CFLAGS = -g -Wall

default: mdb-lookup-server-nc-1 mdb-lookup-server-nc-2

mdb-lookup-server-nc-1: mdb-lookup-server-nc-1.o

mdb-lookup-server-nc-1.o: mdb-lookup-server-nc-1.c

mdb-lookup-server-nc-2: mdb-lookup-server-nc-2.o

mdb-lookup-server-nc-2.o: mdb-lookup-server-nc-2.c

.PHONY: clean
clean:
        rm -rf *.o *~ mypipe-* mdb-lookup-server-nc-1 mdb-lookup-server-nc-2

.PHONY: all
all: clean default
