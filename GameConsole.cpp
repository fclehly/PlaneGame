#include "GameConsole.h"
#include <iostream>

#include <time.h>
#include <string>
#include <iostream>
using namespace std;


GameConsole::GameConsole()
{
	state = STATE_GAME_ON;
    score = 0;
    h_std_input = GetStdHandle(STD_INPUT_HANDLE);
}


GameConsole::~GameConsole()
{
}

void GameConsole::init_player()
{
    player.set_shape('W');
    player.set_position(MAX_COL / 2, MAX_ROW - 1);
    player.draw();
}

void GameConsole::init_bullet()
{
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        bullet[i].set_shape('^');
    }
}

void GameConsole::init_enemy(int speed)
{
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        enemy[i].set_shape('T');
    }
    EnemyPlane::set_speed(speed);
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

int GameConsole::get_input_vk_code()
{
    ReadConsoleInput(h_std_input, &input_record, 1, &record);
    if (record == 1 && input_record.EventType == KEY_EVENT && input_record.Event.KeyEvent.bKeyDown == TRUE)
    {
        return input_record.Event.KeyEvent.wVirtualKeyCode;
    }
    return -1;
                
}

void GameConsole::move_player(int vk_code)
{
    switch (vk_code)
    {
        case VK_UP:
            player.move_up();
            break;
        case VK_DOWN:
            player.move_down();
            break;
        case VK_LEFT:
            player.move_left();
            break;
        case VK_RIGHT:
            player.move_right();
            break;
    }

}

void GameConsole::move_enemy()
{
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        if (enemy[i].get_visibility())
        {
            if (enemy[i].get_position().Y == MAX_ROW - 1)
            {
                enemy[i].hide();
            }
            else
            {
               enemy[i].move_down(); 
            }
            if (enemy[i].is_collision(player.get_position()))
            {
                state = STATE_GAME_END;
            }
        }
    }
}

void GameConsole::move_bullet()
{
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        if (bullet[i].get_visibility())
        {
            if (bullet[i].get_position().Y == MIN_ROW + 1)
            {
                bullet[i].hide();
            }
            else
            {
                bullet[i].move_up();
            }
        }
    }
}

void GameConsole::generate_enemy()
{
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        if (!enemy[i].get_visibility())
        {
            enemy[i].set_position(random(MIN_COL + 1, MAX_COL), MIN_ROW + 1);
            enemy[i].draw();
            break;
        }
    }
}

void GameConsole::generate_bullet()
{ 
    for (int i = 0; i < BULLET_MAX; ++i)
    {
        if (!bullet[i].get_visibility())
        {
            int x = player.get_position().X;
            int y = player.get_position().Y;
            if (y != MIN_ROW + 1)
            {
                bullet[i].set_position(x, y - 1);
                bullet[i].draw();
            }
            break;
        }
    }
}

bool GameConsole::is_enemy_collision()
{
    bool result = false;
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        if (enemy[i].get_visibility())
        {
            for (int j = 0; j < BULLET_MAX; ++j)
            {
                if (bullet[j].get_visibility() && enemy[i].is_collision(bullet[j].get_position()))
                {
                    enemy[i].hide();
                    result = true;
                    break;
                }
            }
        }
    }
    return result;
}

bool GameConsole::is_player_collision()
{
    for (int i = 0; i < ENEMY_MAX; ++i)
    {
        if (enemy[i].get_visibility() && enemy[i].is_collision(player.get_position()))
        {
            return true;
        }
    }
    return false;
}

void GameConsole::start()
{
    draw_background();
    hide_cursor();
    init_player();
    init_enemy(10);
    init_bullet();

    int count = 0;

	while (true)
	{
        if (_kbhit())
        {
            int vk_code = get_input_vk_code();
            switch (vk_code)
            {
                case VK_UP:
                case VK_DOWN:
                case VK_LEFT:
                case VK_RIGHT:
                    move_player(vk_code);
                    break;
                case VK_ESCAPE:
                    state = STATE_GAME_END;
                    break;
                case VK_SPACE:
                    generate_bullet();
                    break;
            }
        }
        
        if (is_player_collision())
        {
            state = STATE_GAME_END;
        }
        
		if (state == STATE_GAME_END)
		{
			break;
		}
         
        if (count % (EnemyPlane::get_speed() * 6) == 0)
        {
            count = 0;
            generate_enemy();
        }
        
        Sleep(50);
        count++;
        
        if (count % 5 == 0)
        {
            move_bullet();
            if (is_enemy_collision())
            {
                score++;
                update_score();
            }
        }
        
        if (count % EnemyPlane::get_speed() == 0)
        {
            move_enemy();
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

