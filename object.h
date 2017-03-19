#ifndef OBJECT_H
#define OBJECT_H

#include "color.h"
#include "vector.h"
#include "ray.h"

class Object
{
    public:
        Object();

        Color getObjectColor();
        double findIntersection(Ray ray);
};

#endif // OBJECT_H
