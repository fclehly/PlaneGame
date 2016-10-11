#pragma once
#include<windows.h>
#include<conio.h>
#define MAX_ROW 24
#define MIN_ROW 0
#define MAX_COL 50
#define MIN_COL 0
class Plane
{
private:
	char shape;
	COORD position;
public:
	Plane(char s, COORD p);
	Plane(char s, int x, int y);
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	void draw();
	~Plane();
};

