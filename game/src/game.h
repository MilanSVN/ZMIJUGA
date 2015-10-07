#ifndef _GAME_H
#define _GAME_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../../include/SDL.h"
#include "../../SDL/src/SDL_Snake.h"

#define FOOD  1

typedef enum
{
  
  UP = 2,
  DOWN = 3,
  LEFT = 4,
  RIGHT = 5  
} DIRECTION;

typedef struct position
{
  uint8_t x;
  uint8_t y;
}POSITION;


uint8_t initGame(void);
void runGame(void);

void setGameOver(void);
void setDirection(uint8_t pomDir);
void quit();
//uint8_t getTest();
#endif

