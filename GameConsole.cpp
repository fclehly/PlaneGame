#include "GameConsole.h"
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<string>
#include "Plane.h"
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


void GameConsole::start()
{
	HANDLE h_in;
	h_in = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD input_record;
	DWORD record;
	

	Plane p1('W', 0, 0);
	p1.draw();

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
}