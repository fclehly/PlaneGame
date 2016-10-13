#pragma once
#include "Cursor.h"
#define STATE_GAME_ON 0
#define STATE_GAME_END 1
#define MAX_ROW 24
#define MIN_ROW 0
#define MAX_COL 50
#define MIN_COL 0
class GameConsole
{
private:
	int state;
	Cursor cursor;
    void hide_cursor();
    void draw_background();
    void print_end_info();
public:
	GameConsole();
	~GameConsole();
	void start();
    void end();
};

