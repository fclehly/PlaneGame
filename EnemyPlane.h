#pragma once
#include "Plane.h"


class EnemyPlane: public Plane
{
private:
    bool flyable;
public:
    EnemyPlane(char s);
    EnemyPlane(char s, COORD p);
    EnemyPlane(char s, int x, int y);
    ~EnemyPlane();
    void fly();
    bool is_flyable();
    void set_flyable(bool value);

};

