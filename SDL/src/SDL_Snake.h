#ifndef _SDL_SNAKE_H
#define _SDL_SNAKE_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../../include/SDL.h"

#define INIT_OFFSET_X 40
#define INIT_OFFSET_PLAYGROUND_X 10
#define INIT_OFFSET_PLAYGROUND_Y 100
#define PLAYGROUND_X 600
#define PLAYGROUND_Y 600
#define SNAKE_X 10
#define SNAKE_Y 10

typedef enum
{
	CONSOLE = 0,
	SDL	= 1
} GUI_TYPE;

typedef struct track_console
{
// 	uint8_t trackID;
// 	uint8_t	ball_prevXpos;
// 	uint8_t ball_prevYpos;
// 	char lane_gui[LENGTH_OF_LANE_CONSOLE][WIDTH_OF_LANE_CONSOLE];
// 	char table_gui[LENGTH_OF_TABLE_CONSOLE][WIDTH_OF_TABLE_CONSOLE];
	
}TRACK_CONSOLE;

SDL_Rect getPositionForLastPic(void); ///< For testing
uint8_t drawPic (SDL_Rect dstOffset, SDL_Surface* pic); ///< This function returns 0 if successful, or -1 if there was an error.
uint8_t initGUI(void); 
void quit();
#endif

