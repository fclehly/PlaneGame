#include "Bullet.h"

Bullet::Bullet(char s, COORD p)
{
	shape = s;
	position.X = p.X;
	position.Y = p.Y;
}

Bullet::Bullet(char s, int x, int y)
{
	shape = s;
	position.X = x;
	position.Y = y;
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	Cursor cursor(position);
	cursor.set_cursor();
	cout << shape;
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

