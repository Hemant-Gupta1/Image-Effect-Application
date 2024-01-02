#include "Sepia.h"
#include <vector>
using namespace std;

// Function to apply sepia tone effect to an image represented by a 2D vector of Pixel objects
void applySepia(vector<vector<Pixel>> &imageVector)
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

            // Calculate sepia-toned RGB values
            int sepiaR = static_cast<int>(0.393 * r + 0.769 * g + 0.189 * b);
            int sepiaG = static_cast<int>(0.349 * r + 0.686 * g + 0.168 * b);
            int sepiaB = static_cast<int>(0.272 * r + 0.534 * g + 0.131 * b);

            // Conditions to check if sepia-toned RGB values have exceeded 255
            imageVector[i][j].r = (sepiaR > 255) ? 255 : sepiaR;
            imageVector[i][j].g = (sepiaG > 255) ? 255 : sepiaG;
            imageVector[i][j].b = (sepiaB > 255) ? 255 : sepiaB;
        }
    }
}