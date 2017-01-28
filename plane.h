#ifndef PLANE_H
#define PLANE_H

#include <cmath>

#include "object.h"
#include "color.h"
#include "vector.h"

class Plane : public Object
{
    public:
        Plane();
        Plane(Vector normal, double distance, Color color);

        Vector getPerpendicular();
        double getDistance();
        Color getColor();
        double intersection(Ray ray);

    private:
        Vector mPerpendicular;
        double mDistance;   //Distance from Origin
        Color mColor;
};

#endif // PLANE_H
