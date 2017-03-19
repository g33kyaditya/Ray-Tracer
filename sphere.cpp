#include "sphere.h"

#include <cmath>

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

Vector Sphere::getPerpendicularAt(Vector point)
{
    Vector result = (point+(-mCentre)).normalize();
    return result;
}

double Sphere::intersection(Ray ray)
{
    Vector rayOrigin = ray.getOrigin();
    double rayOriginX = rayOrigin.getX();
    double rayOriginY = rayOrigin.getY();
    double rayOriginZ = rayOrigin.getZ();

    Vector rayDirection = ray.getDirection();
    double rayDirectionX = rayDirection.getX();
    double rayDirectionY = rayDirection.getY();
    double rayDirectionZ = rayDirection.getZ();

    double sphereCentreX = mCentre.getX();
    double sphereCentreY = mCentre.getY();
    double sphereCentreZ = mCentre.getZ();

    double a = 1;
    double b = 2*(rayOriginX - sphereCentreX)*rayDirectionX +
               2*(rayOriginY - sphereCentreY)*rayDirectionY +
               2*(rayOriginZ - sphereCentreZ)*rayDirectionZ ;
    double c = pow(rayOriginX - sphereCentreX, 2) +
               pow(rayOriginY - sphereCentreY, 2) +
               pow(rayOriginZ - sphereCentreZ, 2) -
               (mRadius * mRadius)                ;
    double d = b*b - 4*a*c;

    if (d > 0) {
        double root1 = (-1*b - sqrt(d))/2*a;
        if (root1 > 0)
            return root1;
        else {
            double root2 = (-1*b + sqrt(d))/2*a;
            return root2;
        }
    }
    else {
        return -1;
    }
}
