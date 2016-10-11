#pragma once
#include<windows.h>
#include<conio.h>
class Cursor
{
private:
	COORD pos;
public:
	Cursor();
	Cursor(COORD p);
	Cursor(int x, int y);
	~Cursor();
	void hide_cursor();
	COORD get_pos();
	void set_pos(COORD p);
	void set_pos(int x, int y);
	void set_cursor();
	void set_cursor(COORD p);
	void set_cursor(int x, int y);

};

