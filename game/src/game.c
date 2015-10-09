/**
 * @file Game.c
 * @brief Document contains short description of used structures and functions 
 * @author RT-RK Snake
 * @date Oktober, 2015
 */

#include "game.h"

static void moveHead();
static void moveTail();
static uint8_t sRandom();
static void putFood();


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

static void putFood()
{
  uint8_t fX = sRandom() % width;
  uint8_t fY = sRandom() % height;
  while(matrix[fY][fX] != 0)
  {
    fX = sRandom() % width;
    fY = sRandom() % height;
  }
  matrix[fY][fX] = FOOD;
  sdlRect.x = fX * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  sdlRect.y = fY * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  drawFood(sdlRect);
}

static uint8_t sRandom()
{
  uint8_t z;
  z = (9 * z + 3) % 127;
  return z;
}

void setDirection(uint8_t pomDir)
{
  if(direction == UP && pomDir == DOWN)
  {
    return;
  }
  if(direction == DOWN && pomDir == UP)
  {
    return;
  }
  if(direction == LEFT && pomDir == RIGHT)
  {
    return;
  }
  if(direction == RIGHT && pomDir == LEFT)
  {
    return;
  }
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
    sdlRect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
    sdlRect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
    drawSnake(sdlRect);
    putFood();
    scorepp();
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
  matrix[tail.y][tail.x] = 0;
  if(tailDirection == DOWN)
  {
    tail.y = (tail.y + 1) % (height);
  }
  else if(tailDirection == UP)
  { 
    tail.y--;
    if(tail.y <= 0)
    {
      tail.y = height - 1;
    }
  }
  else if(tailDirection == LEFT)
  {
    tail.x--;
    if(tail.x <= 0)
    {
      tail.x = width - 1;
    }
  }
  else if(tailDirection == RIGHT)
  {
    tail.x = (tail.x + 1) % (width);
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

  sdlRect.x = INIT_OFFSET_PLAYGROUND_X;
  sdlRect.y = INIT_OFFSET_PLAYGROUND_Y;
  drawPlayground(sdlRect);

  tail.y = height / 2;
  tail.x = width / 2;
  head.y = height / 2;
  head.x = width / 2;
  matrix[tail.y][tail.x] = RIGHT;
  sdlRect.x = head.x * SNAKE_X + INIT_OFFSET_PLAYGROUND_X;
  sdlRect.y = head.y * SNAKE_Y + INIT_OFFSET_PLAYGROUND_Y;
  drawSnake(sdlRect);
  
  putFood();
 
  return 0;
  
}

void runGame(void)
{
  while(gameOver == 0)
  {
    handleUserCommands();
    if(direction == DOWN)
    {
      matrix[head.y][head.x] = DOWN;
      head.y = (head.y + 1) % (height);
      moveHead();
    }
    else if (direction == UP)
    {
      matrix[head.y][head.x] = UP;
      head.y--;
      if(head.y <= 0) 
      {
	head.y = height - 1;
      }
      moveHead();      
    }
    else if (direction == LEFT)
    {
      matrix[head.y][head.x] = LEFT;
      head.x--;
      if(head.x <= 0) 
      {
	head.x = width - 1;
      }
      moveHead(); 
    }
    else if (direction == RIGHT)
    {
      matrix[head.y][head.x] = RIGHT;
      head.x = (head.x + 1) % (width);
      moveHead();      
    }
    //gameOver = 1; //< For test 3,4,5,6,7
    
    
  }
}


