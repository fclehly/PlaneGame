#pragma once
#include "Cursor.h"
#define STATE_GAME_ON 0
#define STATE_GAME_END 1
class GameConsole
{
private:
	int state;
	Cursor cursor;
    void hide_cursor();
public:
	GameConsole();
	~GameConsole();
	void start();
};

