#pragma once
#include "Plane.h"

class EnemyPlane: public Plane
{
public:
    EnemyPlane(char s, COORD p);
    EnemyPlane(char s, int x, int y);
    ~EnemyPlane();
    void fly();

};

