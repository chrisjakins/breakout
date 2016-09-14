#ifndef AIPADDLE_H
#define AIPADDLE_H

#include "visiblegameobject.h"

class AIPaddle : public VisibleGameObject
{
public:
    AIPaddle();
    ~AIPaddle();

    void update(float elapsedTime);
    void draw(sf::RenderWindow &window);

    float getVelocity() const;
private:
    const static float velocity = 410.0f;
    float _velocity;
};

#endif // AIPADDLE_H
