# Set CC to gcc to use gcc as our C compiler
CC = gcc

# -g: include debugging info symbols
# -Wall: enable all warnings
CFLAGS = -g -Wall

main: main.o gcd.o prime.o

# Make uses the following implicit rule to compile a .c file into a .o file:
#
#     $(CC) -c $(CFLAGS) -o <target-.o-file> <the-.c-file>
#
main.o: main.c gcd.h prime.h

gcd.o: gcd.c gcd.h

prime.o: prime.c prime.h

.PHONY: clean
clean:
	rm -f *.o a.out core main

.PHONY: all
all: clean main
