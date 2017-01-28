#ifndef SPHERE_H
#define SPHERE_H

#include <cmath>

#include "object.h"
#include "color.h"
#include "vector.h"

class Sphere : public Object
{
    public:
        Sphere();
        Sphere(Vector centre, double radius, Color color);

        double getRadius();
        Vector getCentre();
        Color getColor();

    private:
        double mRadius;
        Vector mCentre;
        Color mColor;
};

#endif // SPHERE_H
