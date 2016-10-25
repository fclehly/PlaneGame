#include "EnemyPlane.h"

EnemyPlane::EnemyPlane()
{
    
}

EnemyPlane::EnemyPlane(char s): Plane(s)
{
}

EnemyPlane::EnemyPlane(char s, COORD p): Plane(s, p)
{
}

EnemyPlane::EnemyPlane(char s, int x, int y): Plane(s, x, y)
{
}


EnemyPlane::~EnemyPlane()
{
}


void EnemyPlane::set_speed(int value)
{
    speed = value;
}

int EnemyPlane::get_speed()
{
    return speed;
}

int EnemyPlane::speed = 1000;