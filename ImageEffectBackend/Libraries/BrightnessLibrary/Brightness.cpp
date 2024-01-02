#include "Brightness.h"

// Function to apply brightness adjustment to an image represented by a 2D vector of Pixel objects
void applyBrightness(vector<vector<Pixel>> &imageVector, float &amount)
{
    // Get the dimensions of the image
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();

    // Adjust the brightness amount to be centered around zero (subtracting 50)
    amount -= 50.0f;

    // Loop through each pixel in the image
    for (int j = 0; j < imageHeight; j++)
    {
        for (int i = 0; i < imageWidth; i++)
        {
            // Extract the RGB values of the current pixel
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            // Calculate new RGB values with brightness adjustment
            int brightG = static_cast<int>(g + amount);
            int brightB = static_cast<int>(b + amount);
            int brightR = static_cast<int>(r + amount);

            // Conditions to check if RGB values have exceeded 255 or gone below 0
            if (brightR > 255)
            {
                imageVector[i][j].r = 255;
            }
            else if (brightR < 0)
            {
                imageVector[i][j].r = 0;
            }
            else
            {
                imageVector[i][j].r = brightR;
            }

            if (brightG > 255)
            {
                imageVector[i][j].g = 255;
            }
            else if (brightG < 0)
            {
                imageVector[i][j].g = 0;
            }
            else
            {
                imageVector[i][j].g = brightG;
            }

            if (brightB > 255)
            {
                imageVector[i][j].b = 255;
            }
            else if (brightB < 0)
            {
                imageVector[i][j].b = 0;
            }
            else
            {
                imageVector[i][j].b = brightB;
            }
        }
    }
}