CC=gcc

all: game tests build

.PHONY: game tests build

game:
	$(CC) -c src/game.c -o ../build/game.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all
