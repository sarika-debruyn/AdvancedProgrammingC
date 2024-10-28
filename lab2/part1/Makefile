# Set CC to gcc to use gcc as our C compiler
CC = gcc

# Compilation options:
# -g: include debugging info symbols
# -Wall: enable all warnings
CFLAGS = -g -Wall

isort: isort.o
	$(CC) $(LDFLAGS) isort.o $(LDLIBS) -o isort

isort.o: isort.c
	$(CC) $(CFLAGS) -c isort.c

# Clean target to remove all compiled files
.PHONY: clean
clean:
	rm -f *.o isort 

# All target that cleans and rebuilds everything
.PHONY: all
all: clean isort 
