#include "HueSaturation.h"
#include <cmath>
#include <algorithm>
#include <vector>

// Function to apply hue and saturation adjustments to an image represented by a 2D vector of Pixel objects
void applyHueSaturation(vector<vector<Pixel>> &imageVector, float &saturationValue, float &hueValue)
{
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();

    // Normalize saturation and convert hue to degrees
    float s = saturationValue / 100.0;
    hueValue = hueValue * 3.6;

    for (int j = 0; j < imageHeight; j++)
    {
        for (int i = 0; i < imageWidth; i++)
        {
            // Calculate lightness
            float l = (max({imageVector[i][j].r, imageVector[i][j].g, imageVector[i][j].b}) +
                       min({imageVector[i][j].r, imageVector[i][j].g, imageVector[i][j].b})) / 200.0;

            // Calculate chroma, x, and m values
            float cCheck = (1 - abs(2 * l - 1)) * s;
            float xCheck = cCheck * (1 - abs(fmod(hueValue / 60.0, 2) - 1));
            float m = l - cCheck;

            float r, g, b;

            // Determine RGB values based on hue range
            if (hueValue >= 0 && hueValue < 60)
            {
                r = cCheck;
                g = xCheck;
                b = 0;
            }
            else if (hueValue < 120)
            {
                r = xCheck;
                g = cCheck;
                b = 0;
            }
            else if (hueValue < 180)
            {
                r = 0;
                g = cCheck;
                b = xCheck;
            }
            else if (hueValue < 240)
            {
                r = 0;
                g = xCheck;
                b = cCheck;
            }
            else if (hueValue < 300)
            {
                r = xCheck;
                g = 0;
                b = cCheck;
            }
            else if (hueValue < 360)
            {
                r = cCheck;
                g = 0;
                b = xCheck;
            }

            // Set RGB values after adjusting for lightness and chroma
            imageVector[i][j].r = min(255, static_cast<int>(abs(r + m) * 255));
            imageVector[i][j].g = min(255, static_cast<int>(abs(g + m) * 255));
            imageVector[i][j].b = min(255, static_cast<int>(abs(b + m) * 255));
        }
    }
}