#include "gameball.h"
#include "game.h"

#include <cassert>
#include <cmath>

GameBall::GameBall()
    : _velocity(330.0f),
      _elapsedTimeSinceStart(0.0f)
{
    load("images/ball.png");
    assert(isLoaded());

    getSprite().setOrigin(9, 9);
    float random_number = std::rand() % 360 + 1;
    _angle = random_number;
}

GameBall::~GameBall()
{
}

void GameBall::update(float elapsedTime)
{
    _elapsedTimeSinceStart += elapsedTime;

    if(_elapsedTimeSinceStart < 3.0f)
        return;

    float moveAmount = _velocity * elapsedTime;

    float moveByX = linearVelocityX(_angle) * moveAmount;
    float moveByY = linearVelocityY(_angle) * moveAmount;

    // top/bottom bounds collision
    if(getPosition().y + moveByY <= 0 + getHeight() / 2 || getPosition().y + getHeight() / 2 + moveByY >= Game::SCREEN_HEIGHT)
    {
        _angle = 180.0f - _angle;
        moveByY = -moveByY;
    }

    // paddle collision below
    PlayerPaddle* player1 = dynamic_cast<PlayerPaddle*>(Game::getGameObjectManager().get("Paddle1"));
    if(player1 != NULL)
    {
        sf::Rect<float> p1BB = player1->getBoundingRect();

        if(p1BB.intersects(getBoundingRect()))
        {
            _angle = 360.0f - _angle;

            moveByX = -moveByX;

            if(getBoundingRect().width < player1->getBoundingRect().left)
                setPosition(player1->getBoundingRect().left - getWidth() / 2 - 1, getPosition().y);

            // add english
            float playerVelocity = player1->getVelocity();
            if(playerVelocity < 0)
            {
                _angle -= 20.0f;
                if(_angle < 90) _angle = 180.0f - _angle;
            }
            else if(playerVelocity > 0)
            {
                _angle += 20.0f;
                if(_angle > 270.0f) _angle = _angle - 90.0f;
            }

            // so the ball constantly increases speed
            _velocity += 35.0f;
        }

        // BELOW IS END OF ROUND/POINT SCORING SHTUFF
        // left side of screen
        // fix this
        if(getPosition().x - getWidth() / 2 + moveByX <= 0)
        {
            _angle = 360.0f - _angle;
            moveByX = -moveByX;
        }

        // right (player) side of screen, include point scoring for opponent
        if(getPosition().x + getWidth() / 2 + moveByX >= Game::SCREEN_WIDTH)
        {
            getSprite().setPosition(Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2);
            _angle = (rand() % 360) + 1;
            _velocity = 230.0f;
            _elapsedTimeSinceStart = 0.0f;
        }

        getSprite().move(moveByX, moveByY);
    }
}

float GameBall::linearVelocityX(float angle)
{
    angle -= 90;
    if(angle < 0) angle = 360 + angle;
    return (float)std::cos(angle * (3.1415926 / 180.0f));
}

float GameBall::linearVelocityY(float angle)
{
    angle -= 90;
    if(angle < 0) angle = 360 + angle;
    return (float)std::sin(angle * (3.1415926 / 180.0f));
}
