#include "plane.h"

Plane::Plane()
{
    mPerpendicular = Vector(1, 0, 0);
    mDistance = 0;
    mColor = Color(0.5, 0.5, 0.5, 0);
}

Plane::Plane(Vector normal, double distance, Color color)
{
    mDistance = distance;
    mPerpendicular = normal;
    mColor = color;
}

double Plane::getDistance()
{
    return mDistance;
}

Color Plane::getColor()
{
    return mColor;
}

Vector Plane::getPerpendicular()
{
    return mPerpendicular;
}

double Plane::intersection(Ray ray)
{
    double theta = ray.getDirection().dotProduct(mPerpendicular);

    if (theta == 0)             // Parallel to Plane, hence never intersect it
        return -1;
    else {
        double temp = mPerpendicular.dotProduct(ray.getOrigin()+(-(mPerpendicular.multiply(mDistance))));
        return -1*temp/theta;
    }
}
