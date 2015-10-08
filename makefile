all: score SDL_Snake main build game

.PHONY: score SDL_Snake main build game

score:
	$(MAKE) -C score all

SDL_Snake:
	$(MAKE) -C SDL_Snake all

main:
	$(MAKE) -C main all

build:
	$(MAKE) -C build all

game:
	$(MAKE) -C game all

