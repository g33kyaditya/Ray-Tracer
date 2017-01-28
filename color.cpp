#include "color.h"

Color::Color()
{
    mRed = 0.5;
    mGreen = 0.5;
    mBlue = 0.5;
}

Color::Color(double red, double green, double blue, double intensity)
{
    mRed = red;
    mGreen = green;
    mBlue = blue;
    mIntensity = intensity;
}

double Color::getRed()
{
    return mRed;
}

double Color::getGreen()
{
    return mGreen;
}

double Color::getBlue()
{
    return mBlue;
}

double Color::getIntensity()
{
    return mIntensity;
}

void Color::setRed(double red)
{
    mRed = red;
}

void Color::setGreen(double green)
{
    mGreen = green;
}

void Color::setBlue(double blue)
{
    mBlue = blue;
}

void Color::setIntensity(double intensity)
{
    mIntensity = intensity;
}
