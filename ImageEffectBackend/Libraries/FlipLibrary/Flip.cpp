#include "Flip.h"
#include <vector>
#include <algorithm>
#include "../Pixel.h"

using namespace std;

// Function to apply horizontal and vertical flips to an image represented by a 2D vector of Pixel objects
void ApplyFlip(vector<vector<Pixel>> &image, int horizontalFlipValue, int verticalFlipValue)
{
    // Check if a vertical flip is requested
    if (verticalFlipValue != 0)
    {
        // Reverse the order of rows in the entire image
        reverse(image.begin(), image.end());
    }

    // Check if a horizontal flip is requested
    if (horizontalFlipValue != 0)
    {
        // Reverse the order of pixels in each row of the image
        for (vector<Pixel> &row : image)
        {
            reverse(row.begin(), row.end());
        }
    }
}