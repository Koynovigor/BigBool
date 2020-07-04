all: build clean

build: bigbool.c bool.o
	@gcc -g -Wall -o bigbool ./bigbool.c ./bool.o

bool.o: bool.c bool.h
	@gcc -g -c -o bool.o ./bool.c

clean:
	@rm -f ./bool.o

