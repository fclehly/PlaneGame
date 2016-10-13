#include "GameConsole.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string>
#include "Cursor.h"
#include "PlayerPlane.h"
#include "EnemyPlane.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;



GameConsole::GameConsole()
{
	state = STATE_GAME_ON;
}


GameConsole::~GameConsole()
{
}

void GameConsole::draw_background()
{
    Cursor cursor;
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
}

void GameConsole::hide_cursor()
{
    CONSOLE_CURSOR_INFO info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void GameConsole::print_end_info()
{
    Cursor cursor(40, 12);
    cursor.set_cursor();
    cout << "END" << endl;
    cursor.set_cursor(MIN_COL, MAX_ROW);
}

void GameConsole::start()
{
    draw_background();
    hide_cursor();
	HANDLE h_in;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD input_record;
	DWORD record;
	

	PlayerPlane p1('W', 1, 1);
	p1.draw();
    EnemyPlane e1('T', 15, 1);

	while (true)
	{
		ReadConsoleInput(h_in, &input_record, 1, &record);
		if (record == 1 && input_record.EventType == KEY_EVENT && input_record.Event.KeyEvent.bKeyDown == TRUE)
		{

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
                e1.fly();
                break;
			case VK_ESCAPE:
				state = STATE_GAME_END;
				break;
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