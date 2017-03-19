#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "defines.h"
#include "vector.h"
#include "camera.h"
#include "color.h"
#include "light.h"
#include "sphere.h"
#include "plane.h"

using namespace std;

int findClosestObject(vector<double> intersections) {
    int result;
    if (intersections.empty())
        return -1;

    if (intersections.size() == 1) {
        if (intersections[0] > 0)
            return 0;
        else
            return -1;
    }

    double max = *std::max_element(intersections.begin(), intersections.end());
    if (max > 0) {
        for (int i = 0; i < intersections.size(); i++) {
            if (intersections[i] <= max && intersections[i] > 0) {
                max = intersections[i];
                result = i;
            }
        }
        return result;
    }
    return -1;
}

int main(int argc, char * argv[]) {

    int dpi = 72;
    int width = 640;
    int height = 480;
    int current;
    int total = width * height;
    RGB * pixels = new RGB[total];
    int aspectRatio = (double)width/(double)height;
    double xAmount, yAmount;

    Vector X(1, 0, 0);
    Vector Y(0, 1, 0);
    Vector Z(0, 0, 1);
    Vector Origin(0, 0, 0);

    // Camera Spec
    Vector cameraSource(3, 1.5, -4);
    Vector cameraDest(0, 0, 0);
    Vector difference(cameraSource.getX() - cameraDest.getX(), cameraSource.getY() - cameraDest.getY(), cameraSource.getZ() - cameraDest.getZ());
    Vector cameraDirection = -(difference.normalize());
    Vector cameraRight = Y.crossProduct(cameraDirection).normalize();
    Vector cameraDown = cameraRight.crossProduct(cameraDirection);
    Camera camera(cameraSource, cameraDirection, cameraRight, cameraDown);

    //Light Spec
    Color whiteLight = Color(1, 1, 1, 0);
    Vector lightPosition(-7, 10, -10);
    Light sceneLight(lightPosition, whiteLight);

    //Sphere Spec
    Color greenColor = Color(0.5, 1.0, 0.5, 0.3);
    Sphere sceneSphere(Origin, 10, greenColor);

    //Plane Spec
    Color purpleColor(153, 0, 153, 0);
    Plane scenePlane(Y, -1, purpleColor);

    vector<Object*> sceneObjects;
    sceneObjects.push_back(dynamic_cast<Object*>(&sceneSphere));
    sceneObjects.push_back(dynamic_cast<Object*>(&scenePlane));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            current = y * width + x;

            // Image Plane Spec for Camera
            if (width > height) {
                xAmount = ((x + 0.5)/width)*aspectRatio - ((width - height)/(double)(height/2));
                yAmount = ((height - y) + 0.5)/height;
            }
            else if (height > width) {
                xAmount = (x + 0.5)/width;
                yAmount = (((height - y) + 0.5)/height)/aspectRatio - ((height - width)/(double)width/2);
            }
            else {
                xAmount = (x + 0.5)/width;
                yAmount = ((height - y) + 0.5)/height;
            }

            Vector cameraRayFromOrigin = camera.getPosition();
            Vector cameraRayDirection = cameraDirection + (cameraRight.multiply(xAmount - 0.5)+(cameraDown.multiply(yAmount - 0.5))).normalize();
            Ray cameraRay(cameraRayFromOrigin, cameraRayDirection);

            //Find intersection of Object with Camera Ray
            vector<double> intersections;
            for (auto object : sceneObjects) {
                intersections.push_back(object->findIntersection(cameraRay));
            }

            int closestObjectIndex = findClosestObject(intersections);

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
