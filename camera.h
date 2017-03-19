#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"

class Camera
{
    public:
        Camera();
        Camera(Vector position, Vector direction, Vector right, Vector down);

        Vector getPosition();
        Vector getDirection();
        Vector getRight();
        Vector getDown();

    private:
        Vector mPosition;
        Vector mDirection;
        Vector mRight;
        Vector mDown;
};

#endif // CAMERA_H
