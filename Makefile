CC = gcc
# Build configuration
# -g     : enable debugging
# -O0    : no optimization
# -Wall  : show warnings
# -Iinclude : include header directory
CFLAGS = -g -O0 -Wall -Iinclude
# Build all c files in src directory 
SRC = $(wildcard src/*.c)
#output to build/main
OUT = build/main

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -rf build
