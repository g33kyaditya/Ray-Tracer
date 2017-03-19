#ifndef COLOR_H
#define COLOR_H

#include "vector.h"

class Color
{
    public:
        Color();
        Color(double red, double green, double blue, double intensity);

        void setRed(double red);
        void setGreen(double green);
        void setBlue(double blue);
        void setIntensity(double intensity);

        double getRed();
        double getGreen();
        double getBlue();
        double getIntensity();

    private:
        double mRed;
        double mGreen;
        double mBlue;
        double mIntensity;
};

#endif // COLOR_H
