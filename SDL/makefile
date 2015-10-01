CC=gcc

all: SDL_Snake tests build

.PHONY: SDL_Snake tests build

SDL_Snake:
	$(CC) -c src/SDL_Snake.c -o ../build/SDL_Snake.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all
