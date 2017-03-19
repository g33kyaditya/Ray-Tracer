#include "camera.h"

Camera::Camera()
{
    mPosition = Vector(0, 0, 0);
    mDirection = Vector(0, 1, 0);
    mDown = Vector(0, 0, 0);
    mRight = Vector(0, 0, 0);
}

Camera::Camera(Vector position, Vector direction, Vector right, Vector down)
{
    mPosition = position;
    mDirection = direction;
    mRight = right;
    mDown = down;
}

Vector Camera::getDirection()
{
    return mDirection;
}

Vector Camera::getDown()
{
    return mDown;
}

Vector Camera::getPosition()
{
    return mPosition;
}

Vector Camera::getRight()
{
    return mRight;
}
