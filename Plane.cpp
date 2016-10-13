#include "Plane.h"
#include "Cursor.h"
#include <iostream>
using namespace std;



Plane::Plane(char s, COORD p)
{
    visibility = false;
	shape = s;
	position.X = p.X % MAX_COL;
	position.Y = p.Y % MAX_ROW;
}

Plane::Plane(char s, int x, int y)
{
    visibility = false;
	shape = s;
	position.X = x % MAX_COL;
	position.Y = y % MAX_ROW;
}

Plane::~Plane()
{
}

void Plane::draw()
{
    if (!visibility)
    {
        visibility = true;
        Cursor cursor(position);
        cursor.set_cursor();
        cout << shape;
    }
}

void Plane::hide()
{
    if (visibility)
    {
        visibility = false;
        Cursor cursor(position);
        cursor.set_cursor();
        cout << ' ';
    }
}

void Plane::move_down()
{
	if (position.Y < MAX_ROW - 1)
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
	if (position.Y > MIN_ROW + 1)
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
	if (position.X > MIN_COL + 1)
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
	if (position.X < MAX_COL - 1)
	{
		Cursor cursor(position);
		cursor.set_cursor();
		cout << " ";
		position.X++;
		cursor.set_cursor(position);
		cout << shape;
	}
}