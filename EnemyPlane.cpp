#include "EnemyPlane.h"

EnemyPlane::EnemyPlane(char s, COORD p): Plane(s, p)
{
}

EnemyPlane::EnemyPlane(char s, int x, int y): Plane(s, x, y)
{
}

EnemyPlane::~EnemyPlane()
{
}

void EnemyPlane::fly()
{
    if (position.Y > MIN_ROW && position.Y < MAX_ROW - 1)
    {
        draw();
        for (int i = 0; i < MAX_ROW - 1; ++i)
        {
            Sleep(200);
            move_down();
        }
        hide();
    }
}

