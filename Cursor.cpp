#include "Cursor.h"
using namespace std;


Cursor::Cursor()
{
	set_pos(0, 0);
}

Cursor::Cursor(COORD p)
{
	set_pos(p);
}

Cursor::Cursor(int x, int y)
{
	set_pos(x, y);
}


Cursor::~Cursor()
{
}

COORD Cursor::get_pos()
{
	return pos;
}

void Cursor::set_pos(COORD p)
{
	set_pos(p.X, p.Y);
}

void Cursor::set_pos(int x, int y)
{
	pos.X = x;
	pos.Y = y;
}

void Cursor::set_cursor()
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(out, pos);
}

void Cursor::set_cursor(COORD p)
{
	set_pos(p);
	set_cursor();
}

void Cursor::set_cursor(int x, int y)
{
	set_pos(x, y);
	set_cursor();
}

void Cursor::hide_cursor()
{
	CONSOLE_CURSOR_INFO info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}