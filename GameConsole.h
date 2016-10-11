#pragma once
#include "Cursor.h"
#define STATE_GAME_ON 0
#define STATE_GAME_END 1
class GameConsole
{
private:
	int state;
	Cursor cursor;
public:
	GameConsole();
	~GameConsole();
	void start();
};

