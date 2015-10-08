#ifndef _SDL_SNAKE_H
#define _SDL_SNAKE_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../../include/SDL.h"
#include "../../game/src/game.h"

#define INIT_OFFSET_X 40
#define INIT_OFFSET_PLAYGROUND_X 10
#define INIT_OFFSET_PLAYGROUND_Y 100
#define PLAYGROUND_X 600
#define PLAYGROUND_Y 600
#define SNAKE_X 10
#define SNAKE_Y 10



SDL_Rect getPositionForLastPic(void); ///< For testing
void drawSnake(SDL_Rect dstOffset);
void unDrowSnake(SDL_Rect dstOffset);
void drawPlayground(SDL_Rect dstOffset);
void handleUserCommands(void);
uint8_t drawPic (SDL_Rect dstOffset, SDL_Surface* pic, SDL_Surface* base); ///< This function returns 0 if successful, or -1 if there was an error.
uint8_t initGUI(void); 
//SDL_Surface* getScreen(void);
void quit();

#endif

