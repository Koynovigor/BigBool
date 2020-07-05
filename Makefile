all: clean test build

build: bigbool.c bool.o
	@gcc -g -Wall -o bigbool ./bigbool.c ./bool.o

bool.o: bool.c bool.h
	@gcc -g -c -o bool.o ./bool.c

test: test_criterion

test_criterion: criterion.c bool.o
	@gcc -lcriterion -o test_criterion ./criterion.c ./bool.o
	@./test_criterion

clean:
	@rm -f ./bool.o