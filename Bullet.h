#pragma once
#include "Flyer.h"
#include "Cursor.h"

class Bullet
{
private:
	char shape;
    bool visibility;
    COORD position;
public:
    Bullet(char s, COORD p);
	Bullet(char s, int x, int y);
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	void draw();
    void hide();
    ~Bullet();

};

