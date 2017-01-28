#ifndef RAY_H
#define RAY_H

#include "vector.h"

class Ray
{
    public:
        Ray();
        Ray(Vector origin, Vector direction);

        Vector getOrigin();
        Vector getDirection();

    private:
        Vector mOrigin;
        Vector mDirection;
};

#endif // RAY_H
