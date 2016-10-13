#ifndef BRICKARRAY_H
#define BRICKARRAY_H

#include "brick.h"
#include "visiblegameobject.h"

#include <vector>

class BrickArray : public VisibleGameObject
{
public:
    BrickArray();
    ~BrickArray();

    void update(float elapsedTime);
    void draw(sf::RenderWindow& window);

private:
    const static int rows = 4;
    const static int top = 200;

    std::vector<Brick*> brickLayout;
};

#endif // BRICKARRAY_H
