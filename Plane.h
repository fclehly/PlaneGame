#pragma once

#include "Flyer.h"
#include "Cursor.h"

class Plane: public Flyer
{
protected:
    Cursor cursor;
	char shape;
    bool visibility;
    COORD position;
public:
    Plane();
    Plane(char s);
	Plane(char s, COORD p);
	Plane(char s, int x, int y);
	void move_down();
	void move_up();
	void move_left();
	void move_right();
	void draw();
    void hide();
    bool get_visibility();
    COORD get_position();
    void set_shape(char s);
    void set_position(COORD p);
    void set_position(int x, int y);
    bool is_collision(COORD p);
    bool is_collision(int x, int y);
	~Plane();
};

