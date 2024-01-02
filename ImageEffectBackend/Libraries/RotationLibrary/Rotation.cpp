#include "Rotation.h"

// Function to transpose an image represented as a vector of pixels
void transpose(vector<vector<Pixel>> &imageVector)
{
    int rows = imageVector.size();
    int cols = imageVector[0].size();

    // Create a temporary vector to store the transposed image
    vector<vector<Pixel>> temp(cols, vector<Pixel>(rows));

    // Loop through each element in the original image and assign it to the transposed matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp[j][i] = imageVector[i][j];
        }
    }

    // Update the original image vector with the transposed matrix
    imageVector = temp;
}

// Function to flip an image horizontally (left to right)
void flip(vector<vector<Pixel>> &imageVector)
{
    int rows = imageVector.size();
    int cols = imageVector[0].size();

    // Create a temporary vector to store the flipped image
    vector<vector<Pixel>> temp(rows, vector<Pixel>(cols));

    // Loop through each element in the original image and assign it to the flipped matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp[i][j] = imageVector[i][cols - j - 1];
        }
    }

    // Update the original image vector with the flipped matrix
    imageVector = temp;
}

// Function to apply rotation to an image (90 degrees increments)
void applyRotation(vector<vector<Pixel>> &imageVector, int val)
{
    // Rotate the image based on the specified rotation value
    if (val == 1)
    {
        // Transpose and flip the image once (90 degrees)
        transpose(imageVector);
        flip(imageVector);
    }
    else if (val == 2)
    {
        // Transpose and flip the image twice (180 degrees)
        transpose(imageVector);
        flip(imageVector);
        transpose(imageVector);
        flip(imageVector);
    }
    else if (val == 3)
    {
        // Transpose and flip the image thrice (270 degrees)
        transpose(imageVector);
        flip(imageVector);
        transpose(imageVector);
        flip(imageVector);
        transpose(imageVector);
        flip(imageVector);
    }
    // Do nothing if an invalid rotation value is provided
}