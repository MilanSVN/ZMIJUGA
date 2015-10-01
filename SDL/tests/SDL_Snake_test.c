#include "../../unity/unity_fixture.h"
#include "../src/SDL_Snake.h"
#include "../include/SDL.h"


TEST_GROUP(SDL_Snake_Animation);


TEST_GROUP_RUNNER(SDL_Snake_Animation)
{
	RUN_TEST_CASE(SDL_Snake_Animation, SDL_Init);
	//RUN_TEST_CASE(SDL_Snake_Animation, BMP_Load);
	//RUN_TEST_CASE(SDL_Snake_Animation, Animation);
}

TEST_SETUP(SDL_Snake_Animation)
{

}

TEST_TEAR_DOWN(SDL_Snake_Animation)
{
  quit();
}

// Prvi test - SDL inicijalizacija
TEST(SDL_Snake_Animation, SDL_Init)
{
  TEST_ASSERT_EQUAL(0, initGUI());
}

// Drugi test - Ucitavanje resursa
TEST(SDL_Snake_Animation, BMP_Load)
{
  TEST_ASSERT_EQUAL(0, initGUI());
}

// Treci test - Animacija
TEST(SDL_Snake_Animation, Animation)
{
// 	initGUI(SDL);
// 	int it = 0;
// 	for (;it < 10; it++)
// 	{
// 	  pins.pins[it] = it % 2;
// 	}
// 	
// 	bp1.x = 15;
// 	bp2.x = 125;
// 	
// 	bg1.lane_number = 0;
// 	bg2.lane_number = 2;
// 	drawKnockedPinsAndTable(&bg1, 1, pins);
// 	drawKnockedPinsAndTable(&bg2, 1, pins);
// 	uint32_t i;
// 	for (i = 0; i < 450; i++)
// 	{	
// 		SDL_Delay(10);
// 		bp1.y = i;
// 		bp2.y = i;
// 		if (i < 300)
// 		animateBallMovement(&bg1, 0, bp1);
// 		animateBallMovement(&bg2, 0, bp2);
// 		SDL_Delay(5);
// 		//drawKnockedPinsAndTable(&bg1, 2, pins);
// 		//drawKnockedPinsAndTable(&bg2, 3, pins);
// 		//drawKnockedPinsAndTable(&bg1, 1, pins);
// 	}
// 	drawKnockedPinsAndTable(&bg1, 1, pins);
// 	SDL_Delay(2000);
// 	drawKnockedPinsAndTable(&bg1, 1, pins);
// 	TEST_ASSERT_EQUAL(0, 0);
}




