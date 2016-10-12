#include "brickarray.h"

BrickArray::BrickArray()
{
    brickArray = new Brick*[rows];
    for(int r = 0; r < rows; r++)
    {
        brickArray[r] = new Brick[columns];
    }
}

BrickArray::~BrickArray()
{

}

void BrickArray::update(float elapsedTime)
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {

        }
    }
}
