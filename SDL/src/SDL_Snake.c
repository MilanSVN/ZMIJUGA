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
static SDL_Surface* food = NULL;
static SDL_Surface* text = NULL;
//static TTF_Font *font = NULL;

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

void drawScore(uint8_t valueOfScore)
{
  printf("\n YOUR SCORE IS: %d \n",valueOfScore);
  SDL_Delay(50);
//    // Write text to surface
//    SDL_Color text_color = {255, 255, 255};
//    
//    text = TTF_RenderText_Solid(font, ((char)valueOfScore), text_color);
//    
//    sdlRect.x = 100;
//    sdlRect.y = 25;
//    drawPic (sdlRect, text, screen);
}
void drawFood(SDL_Rect dstOffset)
{
  drawPic (dstOffset, food, screen);
}
void drawSnake(SDL_Rect dstOffset)
{
  drawPic (dstOffset, snake, screen);
  SDL_Delay(50); //< Speed of game
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
  //background = SDL_LoadBMP("/home/milan/ZMIJUGA/resources/playgound.bmp");
  playgound = SDL_LoadBMP("/home/milan/ZMIJUGA/resources/playgound.bmp");
  snake = SDL_LoadBMP("/home/milan/ZMIJUGA/resources/snake.bmp");
  delSnake = SDL_LoadBMP("/home/milan/ZMIJUGA/resources/delSnake.bmp");
  food = SDL_LoadBMP("/home/milan/ZMIJUGA/resources/food.bmp");
  
  //font = TTF_OpenFont("FreeSans.ttf", 24);


  if (screen == NULL || background == NULL || snake == NULL || delSnake == NULL || food == NULL)
  {
    return 2;
  }

  SDL_WM_SetCaption("Snake", NULL);
  
  /* Enable Unicode translation */
  SDL_EnableUNICODE( 1 );
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL/8);
  
//    SDL_Color text_color = {255, 255, 255};
//    text = TTF_RenderText_Solid(font, "Score:", text_color);
//    
//    sdlRect.x = 50;
//    sdlRect.y = 25;
//    drawPic (sdlRect, text, screen);
  
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
  SDL_FreeSurface(snake);
  SDL_FreeSurface(screen);	
  SDL_FreeSurface(delSnake);
  SDL_FreeSurface(playgound);
  SDL_FreeSurface(food);
  SDL_FreeSurface(background);
  SDL_FreeSurface(text);
  
  SDL_Quit(); 
}
// SDL GUI END

