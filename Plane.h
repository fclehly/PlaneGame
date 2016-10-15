#pragma once

#include "Flyer.h"

class Plane: public Flyer
{
protected:
	char shape;
    bool visibility;
    COORD position;
public:
    Plane(char s);
	Plane(char s, COORD p);
	Plane(char s, int x, int y);
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	void draw();
    void hide();
    COORD get_position();
    void set_position(COORD p);
    void set_position(int x, int y);
	~Plane();
};

