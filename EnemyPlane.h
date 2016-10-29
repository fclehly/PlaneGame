#pragma once
#include "Plane.h"


class EnemyPlane: public Plane
{
private:
    static int speed;
    int timer;
public:
    EnemyPlane();
    EnemyPlane(char s);
    EnemyPlane(char s, COORD p);
    EnemyPlane(char s, int x, int y);
    ~EnemyPlane();
    int get_timer();
    void add_timer(int i);
    void reset_timer();
    static int get_speed();
    static void set_speed(int value);
};


