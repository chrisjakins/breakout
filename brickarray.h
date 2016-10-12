#ifndef BRICKARRAY_H
#define BRICKARRAY_H

#include "brick.h"

class BrickArray
{
public:
    BrickArray();
    ~BrickArray();

    void update(float elapsedTime);

private:
    const static int columns = 5;
    const static int rows = 5;

    Brick** brickArray;
};

#endif // BRICKARRAY_H
