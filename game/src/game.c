/**
 * @file Game.c
 * @brief Document contains short description of used structures and functions 
 * @author RT-RK Snake
 * @date Oktober, 2015
 */

#include "game.h"

static SDL_Rect sdlRect;

static SDL_Surface* background = NULL;
static SDL_Surface* playgound = NULL;
static SDL_Surface* snake = NULL; 
static SDL_Surface* delSnake = NULL; 

uint8_t matrix[PLAYGROUND_Y / SNAKE_Y][PLAYGROUND_X / SNAKE_X];
uint8_t height;
uint8_t width;
POSITION head;
POSITION tail;


uint8_t initGame(void)
{
  height = PLAYGROUND_Y / SNAKE_Y;
  width = PLAYGROUND_X / SNAKE_X;
  
  uint8_t i;
  uint8_t j;
  for (i = 0; i < height; i++)
  {
    for (j = 0; j < width; j++)
    {
      matrix[i][j] = 0;
    }
  }
  

  background = SDL_LoadBMP("../resources/background.bmp");
  playgound = SDL_LoadBMP("../resources/background.bmp");
  snake = SDL_LoadBMP("../resources/snake.bmp");
  delSnake = SDL_LoadBMP("../resources/delSnake.bmp");

  if ( playgound == NULL || background == NULL || snake == NULL || delSnake == NULL)
  {
    return 2;
  }
  
 sdlRect.x = INIT_OFFSET_PLAYGROUND_X;
 sdlRect.y = INIT_OFFSET_PLAYGROUND_Y;
 initGUI();
 if (drawPic(sdlRect, playgound) != 0)
 {
   return 3;
 }
  
/*
  Uint32 colorkey3 = SDL_MapRGB( pin -> format, 255, 255, 255);
  SDL_SetColorKey(pin, SDL_SRCCOLORKEY, colorkey3); ///<	Set pin key color to white
*/
  return 0;
}

void quitGame()
{
//   SDL_FreeSurface(background);
//   SDL_FreeSurface(snake);
//   SDL_FreeSurface(screen);	
//   SDL_FreeSurface(delSnake);
//   SDL_FreeSurface(playgound);
//   
//   SDL_Quit(); 
}
// SDL GUI END

