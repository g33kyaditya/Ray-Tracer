#include "sphere.h"

Sphere::Sphere()
{
    mRadius = 1;
    mColor = Color(1.0, 0, 0, 0);
    mCentre = Vector(0, 0, 0);
}

Sphere::Sphere(Vector centre, double radius, Color color)
{
    mRadius = radius;
    mCentre = centre;
    mColor = color;
}

double Sphere::getRadius()
{
    return mRadius;
}

Color Sphere::getColor()
{
    return mColor;
}

Vector Sphere::getCentre()
{
    return mCentre;
}
