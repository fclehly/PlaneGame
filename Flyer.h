#pragma once
#include <windows.h>
#include <conio.h>
#define MAX_ROW 24
#define MIN_ROW 0
#define MAX_COL 50
#define MIN_COL 0
class Flyer
{
public:
    virtual void move_up() = 0;
    virtual void move_down() = 0;
    virtual void move_left() = 0;
    virtual void move_right() = 0;
    virtual void draw() = 0;
    virtual void hide() = 0;

};

