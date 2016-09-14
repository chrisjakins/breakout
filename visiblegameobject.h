#ifndef VISIBLEGAMEOBJECT_H
#define VISIBLEGAMEOBJECT_H

#include <string>

#include "SFML/Graphics.hpp"

class VisibleGameObject
{
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void load(std::string filename);
    virtual void draw(sf::RenderWindow& window);
    virtual void update(float elapsedTime);

    virtual void setPosition(float x, float y);
    virtual sf::Vector2f getPosition() const;
    virtual float getWidth() const;
    virtual float getHeight() const;
    virtual sf::Rect<float> getBoundingRect() const;

    virtual bool isLoaded() const;

protected:
    sf::Sprite& getSprite();

private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    std::string _filename;
    bool _isLoaded;
};

#endif // VISIBLEGAMEOBJECT_H
