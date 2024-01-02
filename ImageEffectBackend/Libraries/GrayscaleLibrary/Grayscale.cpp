#include "Grayscale.h"

// Function to convert an image to grayscale represented by a 2D vector of Pixel objects
void grayscale(vector<vector<Pixel>> &img)
{
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[0].size(); j++)
        {
            // Calculate the grayscale value by averaging RGB values
            int gray = (img[i][j].r + img[i][j].g + img[i][j].b) / 3;

            // Set all RGB values to the calculated grayscale value
            img[i][j].r = gray;
            img[i][j].g = gray;
            img[i][j].b = gray;
        }
    }
}