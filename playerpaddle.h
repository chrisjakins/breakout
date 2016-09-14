#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H

#include "visiblegameobject.h"

class PlayerPaddle : public VisibleGameObject
{
public:
    PlayerPaddle();
    ~PlayerPaddle();

    void update(float elapsedTime);
    void draw(sf::RenderWindow& window);

    float getVelocity() const;
private:
    const static float velocity = 0.1f;
    float _velocity;
};

#endif // PLAYERPADDLE_H
