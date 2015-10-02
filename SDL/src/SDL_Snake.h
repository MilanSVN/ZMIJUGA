#ifndef _SDL_SNAKE_H
#define _SDL_SNAKE_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#include "../include/SDL.h"

#define INIT_OFFSET_X 40


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


uint8_t drawPic (SDL_Rect dstOffset, SDL_Surface* pic);
uint8_t initGUI(void);
void quit();
#endif

