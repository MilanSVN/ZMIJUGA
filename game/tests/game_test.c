#include "../../unity/unity_fixture.h"
#include "../src/game.h"
#include "../../include/SDL.h"
#include "../../SDL/src/SDL_Snake.h"

static SDL_Rect sdlRectT;
static SDL_Surface* pic = NULL;


static SDL_Surface* snake = NULL; 
static SDL_Surface* delSnake = NULL; 

TEST_GROUP(game);


TEST_GROUP_RUNNER(game)
{
  RUN_TEST_CASE(game, Init);

}

TEST_SETUP(game)
{

//initGUI();
//  
//   snake = SDL_LoadBMP("../resources/snake.bmp");
//   delSnake = SDL_LoadBMP("../resources/delSnake.bmp");
}

TEST_TEAR_DOWN(game)
{
//   quit();
//   SDL_FreeSurface(pic);
  
//   SDL_FreeSurface(background);
//   SDL_FreeSurface(snake);
//   SDL_FreeSurface(screen);	
//   SDL_FreeSurface(delSnake);
//   SDL_FreeSurface(playgound);
}

// Prvi test - SDL inicijalizacija
TEST(game, Init)
{
  TEST_ASSERT_EQUAL(0, initGame());
  SDL_Delay(500);
}

// // Drugi test - Crtanje slike
// TEST(SDL_Snake_Animation, drawPicture)
// {
//   sdlRectT.x = 10;
//   sdlRectT.y = 10;
//   uint8_t a = 5;
//   a = drawPic (sdlRectT, pic);
//   TEST_ASSERT_EQUAL(0, a);
//   
// }
// 
// // Treci test - Animacija
// TEST(SDL_Snake_Animation, drawPlayground)
// {
//   sdlRectT.x = INIT_OFFSET_PLAYGROUND_X;
//   sdlRectT.y = INIT_OFFSET_PLAYGROUND_Y;
//   drawPic (sdlRectT, background);
//   
//   sdlRectT = getPositionForLastPic();
//   TEST_ASSERT_EQUAL(INIT_OFFSET_PLAYGROUND_X, sdlRectT.x);
//   TEST_ASSERT_EQUAL(INIT_OFFSET_PLAYGROUND_Y, sdlRectT.y);
//   SDL_Delay(5000);
// 
// }
// 
// 
// 
// 
