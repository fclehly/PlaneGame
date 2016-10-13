#include "Bullet.h"
#include <iostream>
using namespace std;

Bullet::Bullet(char s, COORD p)
{
    visibility = false;
	shape = s;
	position.X = p.X;
	position.Y = p.Y;
}

Bullet::Bullet(char s, int x, int y)
{
    visibility = false;
	shape = s;
	position.X = x;
	position.Y = y;
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
   if (!visibility)
    {
        visibility = true;
        Cursor cursor(position);
        cursor.set_cursor();
        cout << shape;
    }
}

void Bullet::hide()
{
    if (visibility)
    {
        visibility = false;
        Cursor cursor(position);
        cursor.set_cursor();
        cout << ' ';
    }
}

void Bullet::move_down()
{
}

void Bullet::move_up()
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

void Bullet::move_left()
{

}

void Bullet::move_right()
{
}

