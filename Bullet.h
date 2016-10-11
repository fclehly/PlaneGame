#pragma once
#include "Flyer.h"

class Bullet
{
private:
	char shape;
    COORD position;
public:
    Bullet(char s, COORD p);
	Bullet(char s, int x, int y);
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	void draw();
    ~Bullet();

};

