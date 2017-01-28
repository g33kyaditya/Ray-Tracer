#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "vector.h"
#include "camera.h"
#include "color.h"
#include "light.h"
#include "sphere.h"
#include "plane.h"

struct RGB{
    double red;
    double green;
    double blue;
};

void saveBitmap(const char * fileName, int width, int height, int dpi, RGB * data) {
    FILE *file;
    int k = width * height;
    int s = 4 * k;
    int fileSize = 54 + s; 

    double factor = 39.375;
    int m = static_cast<int>(factor);

    int ppm = dpi * m;

    unsigned char bitmapFileHeader[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    unsigned char bitmapInfoHeader[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};

    bitmapFileHeader[2] = (unsigned char) (fileSize);
    bitmapFileHeader[3] = (unsigned char) (fileSize >> 8);
    bitmapFileHeader[4] = (unsigned char) (fileSize >> 16);
    bitmapFileHeader[5] = (unsigned char) (fileSize >> 24);

    bitmapInfoHeader[4] = (unsigned char) (width);
    bitmapInfoHeader[5] = (unsigned char) (width >> 8);
    bitmapInfoHeader[6] = (unsigned char) (width >> 16);
    bitmapInfoHeader[7] = (unsigned char) (width >> 24);

    bitmapInfoHeader[8] = (unsigned char) (height);
    bitmapInfoHeader[9] = (unsigned char) (height >> 8);
    bitmapInfoHeader[10] = (unsigned char) (height >> 16);
    bitmapInfoHeader[11] = (unsigned char) (height >> 24);

    bitmapInfoHeader[21] = (unsigned char) (s);
    bitmapInfoHeader[22] = (unsigned char) (s >> 8);
    bitmapInfoHeader[23] = (unsigned char) (s >> 16);
    bitmapInfoHeader[24] = (unsigned char) (s >> 24);

    bitmapInfoHeader[25] = (unsigned char) (ppm);
    bitmapInfoHeader[26] = (unsigned char) (ppm >> 8);
    bitmapInfoHeader[27] = (unsigned char) (ppm >> 16);
    bitmapInfoHeader[28] = (unsigned char) (ppm >> 24);

    bitmapInfoHeader[29] = (unsigned char) (ppm);
    bitmapInfoHeader[30] = (unsigned char) (ppm >> 8);
    bitmapInfoHeader[31] = (unsigned char) (ppm >> 16);
    bitmapInfoHeader[32] = (unsigned char) (ppm >> 24);

    file = fopen(fileName, "wb");
    fwrite(bitmapFileHeader, 1, 14, file);
    fwrite(bitmapInfoHeader, 1, 40, file);

    for (int i = 0; i < k; i++) {
        RGB rgb = data[i];

        double red = data[i].red * 255;
        double green = data[i].green * 255;
        double blue = data[i].blue * 255;

        unsigned char color[3] = { (int)floor(blue), (int)floor(green), (int)floor(red) };
        fwrite(color, 1, 3, file);
    }

    fclose(file);
}

using namespace std;

int main(int argc, char * argv[]) {

    int dpi = 72;
    int width = 640;
    int height = 480;
    int current;
    int total = width * height;
    RGB * pixels = new RGB[total];

    Vector X(1, 0, 0);
    Vector Y(0, 1, 0);
    Vector Z(0, 0, 1);
    Vector Origin(0, 0, 0);

    // Camera Spec
    Vector cameraSource(3, 1.5, -4);
    Vector cameraDest(0, 0, 0);
    Vector difference(cameraSource.getX() - cameraDest.getX(), cameraSource.getY() - cameraDest.getY(), cameraSource.getZ() - cameraDest.getZ());
    Vector cameraDirection = difference.negative().normalize();
    Vector cameraRight = Y.crossProduct(cameraDirection).normalize();
    Vector cameraDown = cameraRight.crossProduct(cameraDirection);
    Camera camera(cameraSource, cameraDirection, cameraRight, cameraDown);

    //Light Spec
    Color whiteLight = Color(1, 1, 1, 0);
    Vector lightPosition(-7, 10, -10);
    Light sceneLight(lightPosition, whiteLight);

    //Object Spec
    Color greenColor = Color(0.5, 1.0, 0.5, 0.3);
    Sphere sceneSphere(Origin, 10, greenColor);

    //Plane Spec
    Color purpleColor(153, 0, 153, 0);
    Plane scenePlane(Y, -1, purpleColor);


    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            current = y * width + x;

            if ((x > 200 && x < 440) && (y > 200 && y < 440)) {
                pixels[current].red = 0;
                pixels[current].green = 1;
                pixels[current].blue = 1;
            }
        }
    }

    saveBitmap("scene.bmp", width, height, dpi, pixels);
    return 0;
}
