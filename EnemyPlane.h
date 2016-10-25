#pragma once
#include "Plane.h"


class EnemyPlane: public Plane
{
private:
    static int speed;
public:
    EnemyPlane();
    EnemyPlane(char s);
    EnemyPlane(char s, COORD p);
    EnemyPlane(char s, int x, int y);
    ~EnemyPlane();
    static int get_speed();
    static void set_speed(int value);
};


