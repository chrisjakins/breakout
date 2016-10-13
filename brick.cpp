#include "brick.h"

#include <cassert>

Brick::Brick(int x, int y, int brickType)
    : state(true)
{
    xPos = x;
    yPos = y;
    type = brickType;
    load("images/brick2.png");
    assert(isLoaded());
    setPosition(xPos, yPos);
}

Brick::~Brick()
{
}

void Brick::update(float elapsedTime)
{

}

void Brick::draw(sf::RenderWindow& window)
{
    if(state)
    {
        VisibleGameObject::draw(window);
    }
}
