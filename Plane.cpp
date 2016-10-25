#include "Plane.h"
#include <iostream>
using namespace std;

Plane::Plane() 
{
    visibility = false;
    position.X = position.Y = 0;
    shape = ' ';
}

Plane::Plane(char s)
{
    visibility = false;
	shape = s;
	position.X = 0;
	position.Y = 0;
}

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
        cursor.set_cursor(position);
        cout << shape << flush;
    }
}

void Plane::hide()
{
    if (visibility)
    {
        visibility = false;
        cursor.set_cursor(position);
        cout << ' ' << flush;
    }
}

bool Plane::get_visibility()
{
    return visibility;
}

COORD Plane::get_position()
{
    return position;
}

void Plane::set_shape(char s) 
{
    shape = s;
}

void Plane::set_position(COORD p)
{
	set_position(p.X, p.Y);
}

void Plane::set_position(int x, int y)
{
	position.X = x;
	position.Y = y;
}

void Plane::move_down()
{
	if (position.Y < MAX_ROW - 1)
	{
		cursor.set_cursor(position);
		cout << " " << flush;
		position.Y++;
		cursor.set_cursor(position);
		cout << shape << flush;
	}
}

void Plane::move_up()
{
	if (position.Y > MIN_ROW + 1)
	{
		cursor.set_cursor(position);
		cout << " " << flush;
		position.Y--;
		cursor.set_cursor(position);
		cout << shape << flush;
	}
}

void Plane::move_left()
{
	if (position.X > MIN_COL + 1)
	{
		cursor.set_cursor(position);
		cout << " " << flush;
		position.X--;
		cursor.set_cursor(position);
		cout << shape << flush;
	}
}

void Plane::move_right()
{
	if (position.X < MAX_COL - 1)
	{
		cursor.set_cursor(position);
		cout << " " << flush;
		position.X++;
		cursor.set_cursor(position);
		cout << shape << flush;
	}
}

bool Plane::is_collision(COORD p)
{
    return is_collision(p.X, p.Y);
}

bool Plane::is_collision(int x, int y)
{
    return (position.X == x && position.Y == y);
}