/**
 * @file SDL_Snake.c
 * @brief Document contains short description of used structures and functions 
 * @author RT-RK Ball_logic
 * @date September, 2015
 */

#include "SDL_Snake.h"

static SDL_Rect sdlRect;

static SDL_Surface* screen = NULL;
static SDL_Surface* background = NULL;
static SDL_Surface* playgound = NULL;
static SDL_Surface* snake = NULL; 
static SDL_Surface* delSnake = NULL; 

static SDL_Event event;

/**
 * @brief Function for testing
 * @retval SDL_Rect Position For Last Pic .
 */
static SDL_Rect testRect;
SDL_Rect getPositionForLastPic(void)
{
  return testRect;
}
/**
 * @brief Get screen
 * @retval SDL_Surface* screen
 */
// SDL_Surface* getScreen(void)
// {
//   return screen;
// }
void unDrowSnake(SDL_Rect dstOffset)
{
  drawPic (dstOffset, delSnake, screen);
}
void drawSnake(SDL_Rect dstOffset)
{
  drawPic (dstOffset, snake, screen);
}

void drawPlayground(SDL_Rect dstOffset)
{
  drawPic (dstOffset, playgound, screen);
}

void handleUserCommands(void)
{
	if (SDL_PollEvent(&event))
	{
		
		if (event.type == SDL_KEYDOWN)
		{
			SDLKey keyPressed = event.key.keysym.sym;
			if ( keyPressed == SDLK_ESCAPE ) setGameOver();
			if ( keyPressed == SDLK_RIGHT ) setDirection(RIGHT);
			if ( keyPressed == SDLK_DOWN )  setDirection(DOWN);
			if ( keyPressed == SDLK_LEFT ) setDirection(LEFT);
			if ( keyPressed == SDLK_UP ) setDirection(UP);
			//if ( keyPressed == SDLK_SPACE ) return 4;
		}
	}
	
}
uint8_t initGUI(void)
{

  
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return 1;
  }
  
  screen = SDL_SetVideoMode(700, 700, 32, SDL_DOUBLEBUF); 
  background = SDL_LoadBMP("../resources/playgound.bmp");
  playgound = SDL_LoadBMP("../resources/playgound.bmp");
  snake = SDL_LoadBMP("../resources/snake.bmp");
  delSnake = SDL_LoadBMP("../resources/delSnake.bmp");


  if (screen == NULL || background == NULL || snake == NULL || delSnake == NULL)
  {
    return 2;
  }

  SDL_WM_SetCaption("Snake", NULL);
  
  /* Enable Unicode translation */
  SDL_EnableUNICODE( 1 );
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL/8);
/*
  Uint32 colorkey3 = SDL_MapRGB( pin -> format, 255, 255, 255);
  SDL_SetColorKey(pin, SDL_SRCCOLORKEY, colorkey3); ///<	Set pin key color to white
*/
  
  return 0;
}
/**
 * @brief 	Function drow pic on screen
 * @param 	dstOffset Position of pic
 * @param 	pic pointer to picture
 * @retval	int8_t	This function returns 0 if successful, or -1 if there was an error.
 */
uint8_t drawPic (SDL_Rect dstOffset, SDL_Surface* pic, SDL_Surface* base)
{
  if (pic == NULL)
  {
    pic = playgound;
  }
  testRect = dstOffset; ///< For testing
  SDL_BlitSurface(pic, NULL, base, &dstOffset); ///<	Add pic to the sceen
  return SDL_Flip(screen);
}





void quit()
{
  SDL_FreeSurface(background);
  SDL_FreeSurface(snake);
  SDL_FreeSurface(screen);	
  SDL_FreeSurface(delSnake);
  SDL_FreeSurface(playgound);
  
  SDL_Quit(); 
}
// SDL GUI END

