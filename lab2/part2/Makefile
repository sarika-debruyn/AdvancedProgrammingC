# Set CC to gcc to use gcc as our C compiler
CC = gcc

# -g: include debugging info symbols
# -Wall: enable all warnings
CFLAGS = -g -Wall

twecho: twecho.o
	$(CC) $(LDFLAGS) twecho.o $(LDLIBS) -o twecho

twecho.o: twecho.c
	$(CC) $(CFLAGS) -c twecho.c

# Clean target to remove all compiled files
.PHONY: clean
clean:
	rm -f *.o twecho

# All target that cleans and rebuilds everything
.PHONY: all
all: clean twecho
