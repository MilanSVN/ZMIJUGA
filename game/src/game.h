#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../../include/SDL.h"
#include "../../SDL/src/SDL_Snake.h"

typedef struct position
{
  uint8_t x;
  uint8_t y;
}POSITION;


uint8_t initGame(void);
void quit();
#endif

