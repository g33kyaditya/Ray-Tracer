#include "ray.h"

Ray::Ray()
{
    mOrigin = Vector(0, 0, 0);
    mDirection = Vector(1, 0, 0);
}

Ray::Ray(Vector origin, Vector direction)
{
    mOrigin = origin;
    mDirection = direction;
}

Vector Ray::getDirection()
{
    return mDirection;
}

Vector Ray::getOrigin()
{
    return mOrigin;
}
