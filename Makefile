all: clean build

build: bigbool.c bool.o
	@gcc -Wall -o bigbool ./bigbool.c ./bool.o

bool.o: bool.c bool.h
	@gcc -c -o bool.o ./bool.c

clean:
	@rm -f ./*.o