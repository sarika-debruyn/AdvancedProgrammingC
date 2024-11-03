CC = gcc

CFLAGS = -g -Wall

LDFLAGS = -g

LDLIBS = 

mylist-test: mylist-test.o libmylist.a

mylist-test.o: mylist-test.c mylist.h

libmylist.a: mylist.o
	ar rcs libmylist.a mylist.o

mylist.o: mylist.c mylist.h

.PHONY: clean
clean:
	rm -f *.o *~ libmylist.a mylist-test 

.PHONY: all
all: clean mylist
