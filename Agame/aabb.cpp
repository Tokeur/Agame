#include "aabb.h"

AABB::AABB()
{
    x=y=w=h=0;
}

bool AABB::collision(AABB other) const
{
    return !((other.x>=x+w)||
             (other.x+other.w<=x)||
             (other.y>=y+h)||
             (other.y+other.h<=y));
}
