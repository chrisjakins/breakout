#include "brick.h"

#include <cassert>

Brick::Brick()
{
    load("images/brick2.png");
    assert(isLoaded());
}

Brick::~Brick()
{
}

void Brick::update(float elapsedTime)
{

}

void Brick::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}
