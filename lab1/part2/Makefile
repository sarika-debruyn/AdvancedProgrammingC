
# Set CC to gcc to use gcc as our C compiler
CC = gcc

# Compilation options:
# -g: include debugging info symbols
# -Wall: enable all warnings
CFLAGS = -g -Wall

LDFLAGS =

LDLIBS =

convert: main.o gcd.o prime.o
	$(CC) $(LDFLAGS) -o convert main.o gcd.o prime.o $(LDLIBS)

main.o: main.c gcd.h prime.h
	$(CC) $(CFLAGS) -c main.c

gcd.o: gcd.c gcd.h
	$(CC) $(CFLAGS) -c gcd.c

prime.o: prime.c prime.h
	$(CC) $(CFLAGS) -c prime.c
 
.PHONY: clean
clean:
	rm -f *.o a.out core myprogram

.PHONY: all
all: clean myprogram
