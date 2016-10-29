#include "EnemyPlane.h"

EnemyPlane::EnemyPlane()
{
    timer = 0;
}

EnemyPlane::EnemyPlane(char s): Plane(s)
{
    timer = 0;
}

EnemyPlane::EnemyPlane(char s, COORD p): Plane(s, p)
{
    timer = 0;
}

EnemyPlane::EnemyPlane(char s, int x, int y): Plane(s, x, y)
{
    timer = 0;
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

int EnemyPlane::get_timer()
{
    return timer;
}

void EnemyPlane::add_timer(int i)
{
    timer += i;
}

void EnemyPlane::reset_timer()
{
    timer = 0;
}

int EnemyPlane::speed = 1000;