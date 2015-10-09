CC=gcc

all: score tests 

.PHONY: game tests build

score:
	$(CC) -c src/score.c -o ../build/score.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all
