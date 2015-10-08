/**
 * @file Game.c
 * @brief Document contains short description of used structures and functions 
 * @author RT-RK Snake
 * @date Oktober, 2015
 */

#include "game.h"

static void moveHead();
static void moveTail();


static SDL_Rect sdlRect;

static SDL_Surface* background = NULL;
static SDL_Surface* playgound = NULL;
static SDL_Surface* snake = NULL; 
static SDL_Surface* delSnake = NULL; 
//static SDL_Surface* screen = NULL;

uint8_t matrix[PLAYGROUND_Y / SNAKE_Y][PLAYGROUND_X / SNAKE_X];
uint8_t height;
uint8_t width;
uint8_t direction;
uint8_t gameOver;
//uint8_t pomDirection;

POSITION head;
POSITION tail;



void setDirection(uint8_t pomDir)
{
  direction = pomDir;
}

void setGameOver()
{
  gameOver = 1;
}

static void moveHead()
{
  uint8_t newPos = matrix[head.y][head.x];
  if(newPos == 0)
  {
    sdlRect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
    sdlRect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
    drawSnake(sdlRect);
    moveTail();
  }
  else if(newPos == FOOD)
  {
    
  }
  else if(newPos > 1)
  {
    gameOver = 1;
  }
}

static void moveTail()
{
  sdlRect.x = tail.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  sdlRect.y = tail.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  unDrowSnake(sdlRect);
  uint8_t tailDirection = matrix[tail.y][tail.x];
  if(tailDirection == UP)
  {
    tail.y = (tail.y + 1) % height;
  }
  else if(tailDirection == DOWN)
  {
    tail.y--;
    if(tail.y < 0)
    {
      tail.y = height;
    }
  }
  else if(tailDirection == LEFT)
  {
    tail.x--;
    if(tail.x < 0)
    {
      tail.x = width;
    }
  }
  else if(tailDirection == RIGHT)
  {
    tail.x = (tail.x + 1) % width;
  }
  
}

uint8_t initGame(void)
{
  height = PLAYGROUND_Y / SNAKE_Y;
  width = PLAYGROUND_X / SNAKE_X;
  
  direction = RIGHT;
  gameOver = 0;
  
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
  //screen = getScreen();

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
 drawPlayground(sdlRect);
//  if (drawPic(sdlRect, playgound, screen) != 0)
//  {
//    return 3;
//  }
 
  return 0;
  
}

void runGame(void)
{
  tail.y = height / 2;
  tail.x = (width / 2);
  head.y = height / 2;
  head.x = width / 2;
  matrix[tail.y][tail.x] = RIGHT;
  sdlRect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  sdlRect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  drawSnake(sdlRect);
  
  while(gameOver == 0)
  {
    handleUserCommands();
    if(direction == UP)
    {
      matrix[head.y][head.x] = UP;
      head.y = (head.y + 1) % height;
      moveHead();
    }
    else if (direction == DOWN)
    {
      matrix[head.y][head.x] = DOWN;
      head.y--;
      if(head.y < 0) 
      {
	head.y = height;
      }
      moveHead();      
    }
    else if (direction == LEFT)
    {
      matrix[head.y][head.x] = LEFT;
      head.x--;
      if(head.x < 0) 
      {
	head.x = width;
      }
      moveHead(); 
    }
    else if (direction == RIGHT)
    {
      matrix[head.y][head.x] = RIGHT;
      head.x = (head.x + 1) % width;
      moveHead();      
    }
    //gameOver = 1; //< For test 3,4,5,6,7
    SDL_Delay(500);
    
  }
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

