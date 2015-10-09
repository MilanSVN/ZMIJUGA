/**
 * @file score.c
 * @brief Document contains short description of used structures and functions 
 * @author RT-RK Snake
 * @date Oktober, 2015
 */

#include "score.h"

static uint8_t valueOfScore;

uint8_t initScore(void)
{
  valueOfScore = 0;
}
void scorepp(void)
{
  valueOfScore++;
  drawScore(valueOfScore);
  
}




