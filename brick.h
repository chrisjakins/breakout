#ifndef BRICK_H
#define BRICK_H

#include "visiblegameobject.h"

class Brick : public VisibleGameObject
{
public:
    Brick(int x, int y, int brickType);\
    ~Brick();

    const static int width = 100;
    const static int height = 50;

    void update(float elapsedTime);
    void draw(sf::RenderWindow& window);
private:
    int xPos;
    int yPos;

    int type;
    bool state;
};

#endif // BRICK_H
