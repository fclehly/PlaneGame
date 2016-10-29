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
    level = LEVEL_NORMAL;
    enemy_num = ENEMY_NUM_NORMAL;
    enemy_speed = ENEMY_SPEED_NORMAL;
    hide_cursor();
}


GameConsole::~GameConsole()
{
}

void GameConsole::start()
{
    
    show_menu();
    
    draw_background();
    
    init_player();
    init_enemy();
    init_bullet();

    int count = 0;

    player.draw();
	while (state != STATE_GAME_END)
	{
        if (kbhit())
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
                case 'P':
                    state = (state == STATE_GAME_EXECUTING) ? STATE_GAME_PAUSE : STATE_GAME_EXECUTING;
                    break;
                default:
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
        
        if (state == STATE_GAME_PAUSE)
        {
            continue;
        }
         
        if (count % (EnemyPlane::get_speed() * (MAX_ROW / enemy_num)) == 0)
        {
            count = 0;
            generate_enemy();
        }
        
        Sleep(50);
        
        count++;
        
        if (count % 2 == 0)
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
            add_enemy_timer();
            enemy_shoot();
        }
        
        if ((count % (EnemyPlane::get_speed() / 4)) == 0)
        {
            move_enemy_bullet();
        }
        
             
	}
    end();
}

void GameConsole::show_menu()
{
    state = STATE_GAME_CHOOSE;
    cout << endl << endl;
    cout << "                               PLANE    GAME" << endl;
    cout << endl << endl;
    cout << "        --------------------------------------------------------------" << endl;
    cout << endl;
    cout << "             Please choose difficulty :" << endl;
    cout << endl;
    cout << "             >>> 1. Normal" << endl;
    cout << "                 2. Hard" << endl;
    cout << endl;
    cout << "        --------------------------------------------------------------" << endl;
    cout << endl << endl;
    char up = 24;
    char down = 25;
    cout << "        Press " << up << ' ' << down << ' ' << "to select level" << endl;
    cout << "        Press Space to confirm" << endl << endl;
    cout << "                                                           editor: fwz" << endl;
    level = LEVEL_NORMAL;
    while (state == STATE_GAME_CHOOSE)
    {
        if (_kbhit())
        {
            int vk_code = get_input_vk_code();
            switch (vk_code)
            {
                case VK_UP:
                    level = LEVEL_NORMAL;
                    cursor.set_cursor(0, 9);
                    cout << "             >>> 1. Normal" << endl;
                    cout << "                 2. Hard" << endl;
                    break;
                case VK_DOWN:
                    level = LEVEL_HARD;
                    cursor.set_cursor(0, 9);
                    cout << "                 1. Normal" << endl;
                    cout << "             >>> 2. Hard" << endl;
                    break;
                case VK_SPACE:
                    state = STATE_GAME_EXECUTING;
                    break;
                default:
                    continue;
                    break;
            }
        }
    }
    switch (level)
    {
        case LEVEL_NORMAL:
            enemy_speed = ENEMY_SPEED_NORMAL;
            enemy_num = ENEMY_NUM_NORMAL;
            break;
        case LEVEL_HARD:
            enemy_speed = ENEMY_SPEED_HARD;
            enemy_num = ENEMY_NUM_HARD;
            break;
        default:
            break;
    }
    system("cls");
}


void GameConsole::init_player()
{
    player.set_shape('W');
    player.set_position(MAX_COL / 2, MAX_ROW - 1);
    player.draw();
}

void GameConsole::init_bullet()
{
    for (int i = 0; i < PLAYER_BULLET_MAX; ++i)
    {
        player_bullet[i].hide();
        player_bullet[i].set_shape('^');
    }
    for (int i = 0; i < ENEMY_BULLET_MAX; ++i)
    {
        enemy_bullet[i].hide();
        enemy_bullet[i].set_shape('|');
    }
}

void GameConsole::init_enemy()
{
    for (int i = 0; i < enemy_num; ++i)
    {
        enemy[i].hide();
        enemy[i].set_shape('T');
    }
    EnemyPlane::set_speed(enemy_speed);
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
    cout << "Press " << up << ' ' << down << ' ' << left << ' ' << right << " to move." << flush;
    cursor.set_cursor(MAX_COL + 4, 1);
    cout << "Press space to shoot." << flush;
    cursor.set_cursor(MAX_COL + 4, 2);
    cout << "Press esc to exit." << flush;
    cursor.set_cursor(MAX_COL + 4, 3);
    cout << "Press P to pause/continue." << flush;
    cursor.set_cursor(MAX_COL + 4, 4);
    cout << "-------------------------";
    cursor.set_cursor(MAX_COL + 4, 5);
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
    cursor.set_cursor(30, 6);
    cout << "END" << flush;
    cursor.set_cursor(30, 8);
    cout << "Final Score: " << score << endl;
    cout << endl;
    cout << endl;
    cout << "        --------------------------------------------------------------" << endl;
    cout << endl << endl;
    cout << "        Restart ?" << endl;
    cout << endl;
    cout << "        >>> 1. Yes" << endl;
    cout << "            2. No" << endl;
    cout << endl << endl;
    cout << "        --------------------------------------------------------------" << endl;
    cout << endl;
    char up = 24;
    char down = 25;
    cout << "        Press " << up << ' ' << down << ' ' << "to select level" << endl;
    cout << "        Press Space to confirm" << endl;
    int choice = 0;
    while (state == STATE_GAME_END)
    {
        
        if (kbhit())
        {
            int vk_code = get_input_vk_code();
            switch (vk_code)
            {
                case VK_UP:
                    cursor.set_cursor(0, 16);
                    choice = 0;
                    cout << "        >>> 1. Yes" << endl;
                    cout << "            2. No" << endl;
                    break;
                case VK_DOWN:
                    choice = 1;
                    cursor.set_cursor(0, 16);
                    cout << "            1. Yes" << endl;
                    cout << "        >>> 2. No" << endl;
                    break;
                case VK_SPACE:
                    state = STATE_GAME_ON;
                    break;
                default:
                    break;
            }
        }
    }
    if (choice == 0)
    {
        system("cls");
        start();
    }
    else 
    {
        cursor.set_cursor(MIN_COL, MAX_ROW);
    }
    
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
    for (int i = 0; i < enemy_num; ++i)
    {
        if (enemy[i].get_visibility())
        {
            if (enemy[i].get_position().Y == MAX_ROW - 1)
            {
                enemy[i].hide();
                enemy[i].reset_timer();
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
    for (int i = 0; i < PLAYER_BULLET_MAX; ++i)
    {
        if (player_bullet[i].get_visibility())
        {
            if (player_bullet[i].get_position().Y == MIN_ROW + 1)
            {
                player_bullet[i].hide();
            }
            else
            {
                player_bullet[i].move_up();
            }
        }
    }
}

void GameConsole::move_enemy_bullet()
{
    for (int i = 0; i < ENEMY_BULLET_MAX; ++i)
    {
        if (enemy_bullet[i].get_visibility())
        {
            if (enemy_bullet[i].get_position().Y == MAX_ROW - 1)
            {
                enemy_bullet[i].hide();
            }
            else
            {
                enemy_bullet[i].move_down();
            }
        }
    }
}

void GameConsole::generate_enemy()
{
    for (int i = 0; i < enemy_num; ++i)
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
    int x = player.get_position().X;
    int y = player.get_position().Y;
    if (y != MIN_ROW + 1)
    {
        for (int i = 0; i < PLAYER_BULLET_MAX; ++i)
        {
            if (!player_bullet[i].get_visibility())
            {
                player_bullet[i].set_position(x, y - 1);
                player_bullet[i].draw();
            
                break;
            }
        }
    
    }
}

void GameConsole::generate_enemy_bullet(int i)
{
    COORD pos = enemy[i].get_position();
    if (pos.Y < MAX_ROW - 1)
    {
        for (int j = 0; j < ENEMY_BULLET_MAX; ++j)
        {
            if (!enemy_bullet[j].get_visibility())
            {
                enemy_bullet[j].set_position(pos.X, pos.Y + 1);
                enemy_bullet[j].draw();
                break;
            }
        }
    }
}

bool GameConsole::is_enemy_collision()
{
    bool result = false;
    for (int i = 0; i < enemy_num; ++i)
    {
        if (enemy[i].get_visibility())
        {
            for (int j = 0; j < PLAYER_BULLET_MAX; ++j)
            {
                if (player_bullet[j].get_visibility() && enemy[i].is_collision(player_bullet[j].get_position()))
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
    for (int i = 0; i < enemy_num; ++i)
    {
        if (enemy[i].get_visibility() && enemy[i].is_collision(player.get_position()))
        {
            return true;
        }
    }
    for (int i = 0; i < ENEMY_BULLET_MAX; ++i)
    {
        if (enemy_bullet[i].get_visibility() && player.is_collision(enemy_bullet[i].get_position()))
        {
            return true;
        }
    }
    return false;
}

void GameConsole::add_enemy_timer()
{
    for (int i = 0; i < enemy_num; ++i)
    {
        if (enemy[i].get_visibility())
        {
            enemy[i].add_timer(1);
        }
    }
}

void GameConsole::enemy_shoot()
{
    for (int i = 0; i < enemy_num; ++i)
    {
        if (enemy[i].get_visibility() && enemy[i].get_timer() == 8)
        {
            generate_enemy_bullet(i);
        }
    }
}



void GameConsole::end()
{
    system("cls");
    print_end_info();
}

