#include "Invert.h"

// Function to apply color inversion to an image represented by a 2D vector of Pixel objects
void applyInvert(vector<vector<Pixel>> &imageVector)
{
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();

    for (int j = 0; j < imageHeight; j++)
    {
        for (int i = 0; i < imageWidth; i++)
        {
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            // Calculate inverted RGB values
            int invertR = 255 - r;
            int invertG = 255 - g;
            int invertB = 255 - b;

            // Conditions to check if inverted RGB values are less than 0
            imageVector[i][j].r = (invertR < 0) ? 0 : invertR;
            imageVector[i][j].g = (invertG < 0) ? 0 : invertG;
            imageVector[i][j].b = (invertB < 0) ? 0 : invertB;
        }
    }
}