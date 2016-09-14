#include "playerpaddle.h"
#include "game.h"
#include "visiblegameobject.h"
#include <cassert>

PlayerPaddle::PlayerPaddle()
    : _velocity(0)
{
    load("images/paddle.png");
    assert(isLoaded());

    //getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(pos.y <= 0)
            _velocity = 0.0f;
        else
            _velocity = -velocity;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(pos.y >= (Game::SCREEN_HEIGHT - getSprite().getLocalBounds().height))
            _velocity = 0.0f;
        else
            _velocity = velocity;
    }
    else
        _velocity = 0.0f;

    getSprite().move(0, _velocity);
}
