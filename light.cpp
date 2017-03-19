#include "light.h"

Light::Light()
{
    mPosition = Vector(0, 0, 0);
    mColor = Color(1, 1, 1, 0);
}

Light::Light(Vector position, Color color)
{
    mPosition = position;
    mColor = color;
}

Vector Light::getPosition()
{
    return mPosition;
}

Color Light::getColor()
{
    return mColor;
}
