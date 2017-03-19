#include "vector.h"

Vector::Vector()
{
    mX = 0;
    mY = 0;
    mZ = 0;
}

Vector::Vector(double x, double y, double z)
{
    mX = x;
    mY = y;
    mZ = z;
}

Vector Vector::operator+(Vector vec)
{
    double x, y, z;
    x = mX + vec.getX();
    y = mY + vec.getY();
    z = mZ + vec.getZ();
    return Vector(x, y, z);
}

Vector Vector::crossProduct(Vector vec)
{
    double x, y, z;
    x = mY * vec.getZ() - mZ * vec.getY();
    y = mZ * vec.getX() - mX * vec.getZ();
    z = mX * vec.getY() - mY * vec.getX();
    return Vector(x, y, z);
}

double Vector::dotProduct(Vector vec)
{
    double result;
    result = mX * vec.getX() + mY * vec.getY() + mZ * vec.getZ();
    return result;
}

Vector Vector::multiply(double factor)
{
    double x, y, z;
    x = mX * factor;
    y = mY * factor;
    z = mZ * factor;
    return Vector(x, y, z);
}

double Vector::magnitude()
{
    return sqrt ( (mX*mX) + (mY*mY) + (mZ*mZ) );
}

Vector Vector::operator-()
{
    return Vector( (-mX), (-mY), (-mZ) );
}

Vector Vector::normalize()
{
    double magnitude = Vector::magnitude();
    return Vector( (mX/magnitude), (mY/magnitude), (mZ/magnitude) );
}

double Vector::getX()
{
    return mX;
}

double Vector::getY()
{
    return mY;
}

double Vector::getZ()
{
    return mZ;
}
