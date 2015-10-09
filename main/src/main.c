#include "main.h"


uint32_t main(uint32_t argc, char* argv[])
{
  initGUI();
  initGame();
  initScore();
  runGame();
  quit();
}

