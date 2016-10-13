#pragma once

#include "Flyer.h"

class Plane: public Flyer
{
protected:
	char shape;
    bool visibility;
    COORD position;
public:
	Plane(char s, COORD p);
	Plane(char s, int x, int y);
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	void draw();
    void hide();
	~Plane();
};

