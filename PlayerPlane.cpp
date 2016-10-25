#include "PlayerPlane.h"

PlayerPlane::PlayerPlane()
{
    
}

PlayerPlane::PlayerPlane(char s, COORD p) : Plane(s, p)
{
}

PlayerPlane::PlayerPlane(char s, int x, int y) : Plane(s, x, y)
{
}

PlayerPlane::~PlayerPlane()
{
}

void PlayerPlane::shoot()
{
    
}
