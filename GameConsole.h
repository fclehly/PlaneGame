#pragma once
#include "Cursor.h"
#include "PlayerPlane.h"
#include "EnemyPlane.h"
#include "Bullet.h"
#include <windows.h>
#include <conio.h>

#define STATE_GAME_ON 0
#define STATE_GAME_END 1
#define STATE_GAME_EXECUTING 2
#define STATE_GAME_CHOOSE 3
#define STATE_GAME_PAUSE 4

#define MAX_ROW 24
#define MIN_ROW 0
#define MAX_COL 50
#define MIN_COL 0

#define ENEMY_MAX 20
#define PLAYER_BULLET_MAX 21
#define ENEMY_BULLET_MAX 20

#define ENEMY_SPEED_NORMAL 12
#define ENEMY_SPEED_HARD 6

#define ENEMY_NUM_NORMAL 5
#define ENEMY_NUM_HARD 10

#define LEVEL_NORMAL 0
#define LEVEL_HARD 1
class GameConsole
{
private:

    HANDLE h_std_input;
    INPUT_RECORD input_record;
	DWORD record;

    int enemy_num;
    int enemy_speed;
    int level;
	int state;
	Cursor cursor;
    int score;
    
    EnemyPlane enemy[ENEMY_MAX];
    Bullet player_bullet[PLAYER_BULLET_MAX];
    Bullet enemy_bullet[ENEMY_BULLET_MAX];
    PlayerPlane player;
    
    void hide_cursor();
    void draw_background();
    void print_end_info();
    int random(int low, int high);
    int get_input_vk_code();
    void update_score();
    void show_menu();
    
    void move_player(int vk_code);
    void move_enemy();
    void move_bullet();
    void move_enemy_bullet();
    
    void generate_enemy();
    void generate_bullet();
    void generate_enemy_bullet(int i);
    
    bool is_enemy_collision();
    bool is_player_collision();
    
    void init_player();
    void init_bullet();
    void init_enemy();
    
    void add_enemy_timer();
    void enemy_shoot();
public:
	GameConsole();
	~GameConsole();
	void start();
    void end();
};

