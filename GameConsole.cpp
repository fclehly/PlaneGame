#include "GameConsole.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>

#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;



GameConsole::GameConsole()
{
	state = STATE_GAME_ON;
    score = 0;
}


GameConsole::~GameConsole()
{
}

void GameConsole::draw_background()
{
    for (int i = 0; i < MAX_COL; ++i)
    {
        cursor.set_cursor(i, MIN_ROW);
        cout << '-';
        cursor.set_cursor(i, MAX_ROW);
        cout << '-';
    }
    for (int i = 0; i < MAX_ROW; ++i)
    {
        cursor.set_cursor(MIN_COL, i);
        cout << '|';
        cursor.set_cursor(MAX_COL, i);
        cout << '|';
    }
    
    cursor.set_cursor(MAX_COL + 4, 0);
    char up = 24;
    char down = 25;
    char right = 26;
    char left = 27;
    cout << "Press " << up << down << left << right << " to move.";
    cursor.set_cursor(MAX_COL + 4, 1);
    cout << "Press space to shoot.";
    cursor.set_cursor(MAX_COL + 4, 2);
    cout << "Press esc to exit.";
    cursor.set_cursor(MAX_COL + 4, 3);
    cout << "-------------------------";
    cursor.set_cursor(MAX_COL + 4, 4);
    cout << "Score:  0";
}

void GameConsole::update_score()
{
    cursor.set_cursor(MAX_COL + 12, 4);
    cout << score << flush;
}

void GameConsole::hide_cursor()
{
    CONSOLE_CURSOR_INFO info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void GameConsole::print_end_info()
{
    cursor.set_cursor(30, 15);
    cout << "END" << flush;
    cursor.set_cursor(30, 17);
    cout << "Final Score: " << score;
    cursor.set_cursor(MIN_COL, MAX_ROW);
}

int GameConsole::random(int low, int high)
{
    int rand_num = low + (rand() % (high - low));
    return rand_num;
}

void GameConsole::start()
{
    draw_background();
    hide_cursor();
	HANDLE h_in;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD input_record;
	DWORD record;
	

	PlayerPlane p1('W', MAX_COL / 2, MAX_ROW - 1);
	p1.draw();
    
    Bullet bullet[BULLET_MAX] = 
    {
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
        Bullet('^', 1, MAX_ROW - 1),
    };
    
    EnemyPlane enemy[ENEMY_MAX] =
    {
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
        EnemyPlane('T', 0, 0),
    };

    int count = 0;
	while (true)
	{
        if (_kbhit())
        {
            ReadConsoleInput(h_in, &input_record, 1, &record);
            if (record == 1 && input_record.EventType == KEY_EVENT && input_record.Event.KeyEvent.bKeyDown == TRUE)
            {
                int j = 0;
                switch (input_record.Event.KeyEvent.wVirtualKeyCode)
                {
                case VK_DOWN:
                    p1.move_down();
                    break;
                case VK_UP:
                    p1.move_up();
                    break;
                case VK_LEFT:
                    p1.move_left();
                    break;
                case VK_RIGHT:
                    p1.move_right();
                    break;
                case VK_SPACE:
                    for (j = 0; j < BULLET_MAX; ++j)
                    {
                        if (!bullet[j].get_visibility())
                        {
                            bullet[j].set_position(p1.get_position().X, p1.get_position().Y - 1);
                            bullet[j].draw();
                            break;
                        }
                    }
                    break;
                case VK_ESCAPE:
                    state = STATE_GAME_END;
                    break;
                }
            }
        }
        Sleep(100);
        count++;
        //bullet move
        for (int i = 0; i < BULLET_MAX; ++i)
        {
            if (bullet[i].get_visibility())
            {
                
                if (bullet[i].get_position().Y == MIN_ROW + 1)
                {
                    bullet[i].hide();
                    bullet[i].set_position(1, MAX_ROW - 1);
                }
                else
                {
                    bullet[i].move_up();
                }
                
            }
        }
        //enemy move
        if (count >= 5)
        {
            count = 0;
            for (int i = 0; i < ENEMY_MAX; ++i)
            {
                if (!enemy[i].is_flyable())
                {
                    enemy[i].set_flyable(true);
                    enemy[i].set_position(random(MIN_COL + 1, MAX_COL - 1), MIN_ROW + 1);
                    enemy[i].draw();
                    break;
                }
            }
            for (int i = 0; i < ENEMY_MAX; ++i)
            {
                if (enemy[i].is_flyable())
                {
                    enemy[i].move_down();
                    if (enemy[i].is_collision(p1.get_position()))
                    {
                        state = STATE_GAME_END;
                        break;
                    }
                    if (enemy[i].get_position().Y == MAX_ROW - 1)
                    {
                        enemy[i].set_flyable(false);
                        enemy[i].hide();
                        enemy[i].set_position(MIN_COL + 1, MIN_ROW + 1);
                    }
                }
            }
        }
        //enemy collision judge
        for (int i = 0; i < BULLET_MAX; ++i)
        {
            if (bullet[i].get_visibility())
            {
                for (int j = 0; j < ENEMY_MAX; ++j)
                {
                    if (enemy[j].is_flyable() && enemy[j].is_collision(bullet[i].get_position()))
                    {
                        enemy[j].hide();
                        enemy[j].set_flyable(false);
                        enemy[j].set_position(MIN_COL + 1, MIN_ROW + 1);
                        bullet[i].hide();
                        bullet[i].set_position(MIN_COL + 1, MAX_ROW - 1);
                        score++;
                        update_score();
                        break;
                    }
                }
            }
        }
        
        
		if (state == STATE_GAME_END)
		{
			break;
		}
	}
    end();
}

void GameConsole::end()
{
    system("cls");
    print_end_info();
}

