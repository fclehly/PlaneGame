#include <iostream>
#include <time.h>
#include "GameConsole.h"
using namespace std;
int main()
{
    srand((int)time(0));
	GameConsole game;
	game.start();
	return 0;
}