#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "color.h"

class Light
{
    public:
        Light();
        Light(Vector position, Color color);

        Vector getPosition();
        Color getColor();

    private:
        Vector mPosition;
        Color mColor;
};

#endif // LIGHT_H
