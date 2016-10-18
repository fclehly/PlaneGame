#pragma once
#include "Cursor.h"
#include "PlayerPlane.h"
#include "EnemyPlane.h"
#include "Bullet.h"
#define STATE_GAME_ON 0
#define STATE_GAME_END 1
#define MAX_ROW 24
#define MIN_ROW 0
#define MAX_COL 50
#define MIN_COL 0
#define ENEMY_MAX 20
#define BULLET_MAX 21
class GameConsole
{
private:

	int state;
	Cursor cursor;
    
    void hide_cursor();
    void draw_background();
    void print_end_info();
    int random(int low, int high);
public:
	GameConsole();
	~GameConsole();
	void start();
    void end();
};

