#include "aipaddle.h"
#include "game.h"
#include "gameball.h"

#include <cassert>

AIPaddle::AIPaddle() :
    _velocity(0)
{
    load("images/paddle.png");
    assert(isLoaded());

    getSprite().setOrigin(getSprite().getLocalBounds().width / 2, getSprite().getLocalBounds().height / 2);
}

AIPaddle::~AIPaddle()
{
}

void AIPaddle::draw(sf::RenderWindow &window)
{
    VisibleGameObject::draw(window);
}

float AIPaddle::getVelocity() const
{
    return _velocity;
}

void AIPaddle::update(float elapsedTime)
{
    const GameBall* gameBall = static_cast<GameBall*>(Game::getGameObjectManager().get("Ball"));
    sf::Vector2f ballPosition = gameBall->getPosition();

    if(getPosition().y - 35 < ballPosition.y)
    {
        if(getPosition().y >= Game::SCREEN_HEIGHT - getSprite().getLocalBounds().height / 2)
            _velocity = 0.0f;
        else
            _velocity = velocity;
    }
    else if(getPosition().y + 35 > ballPosition.y)
    {
        if(getPosition().y <= 0 + getSprite().getLocalBounds().height / 2)
            _velocity = 0.0f;
        else
            _velocity = -velocity;
    }
    else
        _velocity = 0.0f;

    sf::Vector2f pos = this->getPosition();

    if(pos.y <= getSprite().getLocalBounds().top / 2 || pos.y >= (Game::SCREEN_HEIGHT - getSprite().getLocalBounds().top / 2))
        _velocity = -velocity;

    getSprite().move(0, _velocity * elapsedTime);
}
