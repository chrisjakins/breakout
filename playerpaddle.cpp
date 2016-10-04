#include "playerpaddle.h"
#include "game.h"
#include "visiblegameobject.h"
#include <cassert>

PlayerPaddle::PlayerPaddle()
    : _velocity(0)
{
    load("images/paddle.png");
    assert(isLoaded());
}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}

float PlayerPaddle::getVelocity() const
{
    return _velocity;
}

void PlayerPaddle::update(float elapsedTime)
{
    sf::Vector2f pos = this->getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(pos.x <= 0)
            _velocity = 0.0f;
        else
            _velocity = -velocity;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(pos.x >= (Game::SCREEN_WIDTH - getSprite().getLocalBounds().width))
            _velocity = 0.0f;
        else
            _velocity = velocity;
    }
    else
        _velocity = 0.0f;

    getSprite().move(_velocity, 0);
}


//should be fixed
