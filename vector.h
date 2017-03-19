#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class Vector
{
    public:
        Vector();
        Vector(double x, double y, double z);

        Vector normalize();
        double magnitude();
        Vector operator-();
        Vector multiply(double factor);
        double dotProduct(Vector vec);
        Vector crossProduct(Vector vec);
        Vector operator+(Vector vec);

        double getX();
        double getY();
        double getZ();

    private:
        double mX;
        double mY;
        double mZ;
};

#endif // VECTOR_H
