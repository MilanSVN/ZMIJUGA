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
static SDL_Surface* screen = NULL;

uint8_t matrix[PLAYGROUND_Y / SNAKE_Y][PLAYGROUND_X / SNAKE_X];
uint8_t height;
uint8_t width;
uint8_t direction;
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
  screen = getScreen();

  if ( playgound == NULL || background == NULL || snake == NULL || delSnake == NULL)
  {
    return 2;
  }
  
  Uint32 colorkey1 = SDL_MapRGB( snake -> format, 100, 100, 100);
  SDL_SetColorKey(snake, SDL_SRCCOLORKEY, colorkey1); ///< Set snake key color
  //Uint32 colorkey2 = SDL_MapRGB( snake -> format, 110, 100, 100);
  SDL_SetColorKey(playgound, SDL_SRCCOLORKEY, colorkey1); ///< Set snake key color
  
 sdlRect.x = INIT_OFFSET_PLAYGROUND_X;
 sdlRect.y = INIT_OFFSET_PLAYGROUND_Y;
 if (drawPic(sdlRect, playgound, screen) != 0)
 {
   return 3;
 }
 
  return 0;
  
}

void runGame(void)
{
  tail.y = height / 2;
  tail.x = width / 2;
  head.y = height / 2;
  head.x = width / 2;
  matrix[head.y][head.x] = 1;
  sdlRect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  sdlRect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  drawPic(sdlRect, snake, playgound);
  
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

