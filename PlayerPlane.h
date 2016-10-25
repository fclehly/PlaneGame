#pragma once
#include "plane.h"

class PlayerPlane: public Plane
{
public:
    PlayerPlane();
    PlayerPlane(char s, COORD p);
    PlayerPlane(char s, int x, int y);
    ~PlayerPlane();
    void shoot();

};

