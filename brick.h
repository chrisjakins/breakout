#ifndef BRICK_H
#define BRICK_H

#include "visiblegameobject.h"

class Brick : public VisibleGameObject
{
public:
    Brick();\
    ~Brick();

    void update(float elapsedTime);
    void draw(sf::RenderWindow &window);
};

#endif // BRICK_H
