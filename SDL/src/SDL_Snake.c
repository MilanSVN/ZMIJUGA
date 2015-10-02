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

/**
 * @brief Function for testing
 * @retval SDL_Rect Position For Last Pic .
 */
static SDL_Rect testRect;
SDL_Rect getPositionForLastPic(void)
{
  return testRect;
}


uint8_t initGUI(void)
{

  
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return 1;
  }
  
  screen = SDL_SetVideoMode(700, 700, 32, SDL_DOUBLEBUF); 
  background = SDL_LoadBMP("../resources/background.bmp");
  playgound = SDL_LoadBMP("../resources/background.bmp");
  snake = SDL_LoadBMP("../resources/snake.bmp");
  delSnake = SDL_LoadBMP("../resources/delSnake.bmp");


  if (screen == NULL || background == NULL || snake == NULL || delSnake == NULL)
  {
    return 2;
  }

  SDL_WM_SetCaption("Snake", NULL);
/*
  Uint32 colorkey3 = SDL_MapRGB( pin -> format, 255, 255, 255);
  SDL_SetColorKey(pin, SDL_SRCCOLORKEY, colorkey3); ///<	Set pin key color to white
*/
  return 0;
}

uint8_t drawPic (SDL_Rect dstOffset, SDL_Surface* pic)
{
  if (pic == NULL)
  {
    pic = playgound;
  }
  testRect = dstOffset;
  SDL_BlitSurface(pic, NULL, screen, &dstOffset); ///<	Add pic to the sceen
  return SDL_Flip(screen);
}


/**
 * @brief 	Function drow pins on lane
 * @param 	lane	Number of lain (lane ID)
 * @param 	knocked_down_pins	Structure who keep data of knocked pins
 * @retval	int8_t	This function returns 0 if successful, or -1 if there was an error.
 */
/*
static int8_t drawPins(uint8_t lane, KNOCKED_DOWN_PINS knocked_down_pins )
{
  printLane(lane);
  SDL_Rect dstOffset; 

  dstOffset.x = INIT_OFFSET_FOR_PINS_X + (lane) * TWO_LANES_DISTANCE; 
  dstOffset.y = INIT_OFFSET_Y;
  
  int8_t numOfPin = NUM_OF_PINS; 
  int8_t numOfRow;
  int8_t numOfPinsInRow;
  
  for (numOfRow = 4; numOfRow > 0; numOfRow--)
  {
    for(numOfPinsInRow = numOfRow; numOfPinsInRow > 0; numOfPinsInRow--)
    {
      if(knocked_down_pins.pins[--numOfPin] == 0)
      {
	SDL_BlitSurface(pin, NULL, screen, &dstOffset); ///<	Add pin to the sceen
      }
      dstOffset.x += OFFSET_FOR_PINS_X; ///<	Sets  offset for x for next pin
    }
    dstOffset.x = INIT_OFFSET_FOR_PINS_X + (lane) * TWO_LANES_DISTANCE + (4 - numOfRow + 1) * OFFSET_FOR_PINS_X / 2; ///<	Sets initial offset for x for given row
    dstOffset.y += OFFSET_FOR_PINS_Y; ///<	Sets initial offset for y for given row
  }
  
  int8_t j = SDL_Flip(screen);

  return j;
}

static uint8_t drawKnockedPinsAndTable_SDL(BOWLING_GAME* the_game, uint8_t current_player, KNOCKED_DOWN_PINS knocked_down_pins)
{
  drawPins(the_game -> lane_number, knocked_down_pins);

}

static uint8_t animateBallMovement_SDL(BOWLING_GAME* the_game, uint8_t current_player, BALL_POSITION ball_position)
{
	printBall(ball_position.x, ball_position.y, the_game -> lane_number);
	return 0;
}

static void printBall(uint32_t x, uint32_t y, uint8_t lane)  // x,y - centar lopte
{

	// Pozicija na stazi na kojoj se brise lopta
	SDL_Rect dstOffsetDel; 
	dstOffsetDel.x = INIT_OFFSET_X + prevX[lane] + (lane) * TWO_LANES_DISTANCE; 
	dstOffsetDel.y = INIT_OFFSET_Y + LANE_HEIGHT - BALL_DIM - prevY[lane];

	SDL_Rect srcOffsetDel;

	srcOffsetDel.w = BALL_DIM; 
	srcOffsetDel.h = BALL_DIM;
	srcOffsetDel.x = prevX[lane]; 
	srcOffsetDel.y = LANE_HEIGHT - BALL_DIM - prevY[lane];
	// Brisanje prethodno iscrtane lopte
	if (y != 0)
	{
		SDL_BlitSurface(bowling_lane, &srcOffsetDel, screen, &dstOffsetDel);
	}
	// Pozicija na stazi na koju se stavlja lopta
	SDL_Rect dstOffset; 
	dstOffset.x = INIT_OFFSET_X + x + (lane) * TWO_LANES_DISTANCE; 
	dstOffset.y = INIT_OFFSET_Y + LANE_HEIGHT - BALL_DIM - y;

	SDL_Surface* tmp = (y % 30 == 0) ? ball[0] : ball[1];

	SDL_BlitSurface(tmp, NULL, screen, &dstOffset);

	SDL_Flip(screen);

	prevX[lane] = x;
	prevY[lane] = y;
}
*/
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

