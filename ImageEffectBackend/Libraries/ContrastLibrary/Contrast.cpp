#include "Contrast.h"
#include <vector>
using namespace std;

// Function to apply contrast adjustment to an image represented by a 2D vector of Pixel objects
void applyContrast(vector<vector<Pixel>> &imageVector, float &amount)
{
    // Get the dimensions of the image
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();

    // Loop through each pixel in the image
    for (int j = 0; j < imageHeight; j++)
    {
        for (int i = 0; i < imageWidth; i++)
        {
            // Extract the RGB values of the current pixel
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            // Calculate new contrast-adjusted RGB values
            int contrastR = static_cast<int>(amount * (r - 128) + 128);
            int contrastG = static_cast<int>(amount * (g - 128) + 128);
            int contrastB = static_cast<int>(amount * (b - 128) + 128);

            // Conditions to check if RGB values have exceeded 255 or gone below 0
            if (contrastR > 255)
            {
                imageVector[i][j].r = 255;
            }
            else if (contrastR < 0)
            {
                imageVector[i][j].r = 0;
            }
            else
            {
                imageVector[i][j].r = contrastR;
            }

            if (contrastG > 255)
            {
                imageVector[i][j].g = 255;
            }
            else if (contrastG < 0)
            {
                imageVector[i][j].g = 0;
            }
            else
            {
                imageVector[i][j].g = contrastG;
            }

            if (contrastB > 255)
            {
                imageVector[i][j].b = 255;
            }
            else if (contrastB < 0)
            {
                imageVector[i][j].b = 0;
            }
            else
            {
                imageVector[i][j].b = contrastB;
            }
        }
    }
}