#ifndef HUE_SATURATION_H
#define HUE_SATURATION_H
#include "../Pixel.h"
#include <vector>
#include <cmath>
using namespace std;
struct HSV {
    double h, s, v;
};

HSV rgbToHSV( int &r, int &g, int &b);
Pixel hsvToRGB(HSV &hsv);
void applyHueSaturation(vector< vector<Pixel> > &imageVector,float &saturationValue, float &hueValue);

#endif