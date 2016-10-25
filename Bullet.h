#pragma once
#include "Flyer.h"
#include "Cursor.h"

class Bullet: public Flyer
{
private:
	char shape;
    bool visibility;
    COORD position;
    Cursor cursor;
public:
    Bullet();
    Bullet(char s, COORD p);
	Bullet(char s, int x, int y);
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
    ~Bullet();

};

