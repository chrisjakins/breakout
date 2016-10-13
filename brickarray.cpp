#include "brickarray.h"
#include "brick.h"
#include "game.h"

#include <vector>

BrickArray::BrickArray()
{
    for(int r = top; r < top + rows * Brick::height; r += Brick::height)
    {
        for(int c = 0; c < Game::SCREEN_WIDTH; c += Brick::width)
        {
            switch(r % 100)
            {
                case ()
            }

            Brick* brick = new Brick(c, r, 1);
            brickLayout.push_back(brick);
        }
    }
}

BrickArray::~BrickArray()
{

}

void BrickArray::update(float elapsedTime)
{
}

void BrickArray::draw(sf::RenderWindow& window)
{
    std::vector<Brick*>::iterator itr = brickLayout.begin();
    while(itr != brickLayout.end())
    {
        (*itr)->draw(window);
        itr++;
    }
}
