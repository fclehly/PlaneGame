#include "Plane.h"
#include "Cursor.h"
#include <iostream>
using namespace std;



Plane::Plane(char s, COORD p)
{
	shape = s;
	position.X = p.X;
	position.Y = p.Y;
}

Plane::Plane(char s, int x, int y)
{
	shape = s;
	position.X = x;
	position.Y = y;
}

Plane::~Plane()
{
}

void Plane::draw()
{
	Cursor cursor(position);
	cursor.set_cursor();
	cout << shape;
}

void Plane::move_down()
{
	if (position.Y < MAX_ROW)
	{
		Cursor cursor(position);
		cursor.set_cursor();
		cout << " ";
		position.Y++;
		cursor.set_cursor(position);
		cout << shape;
	}
}

void Plane::move_up()
{
	if (position.Y > MIN_ROW)
	{
		Cursor cursor(position);
		cursor.set_cursor();
		cout << " ";
		position.Y--;
		cursor.set_cursor(position);
		cout << shape;
	}
}

void Plane::move_left()
{
	if (position.X > MIN_COL)
	{
		Cursor cursor(position);
		cursor.set_cursor();
		cout << " ";
		position.X--;
		cursor.set_cursor(position);
		cout << shape;
	}
}

void Plane::move_right()
{
	if (position.X < MAX_COL)
	{
		Cursor cursor(position);
		cursor.set_cursor();
		cout << " ";
		position.X++;
		cursor.set_cursor(position);
		cout << shape;
	}
}