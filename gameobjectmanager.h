#ifndef GAMEOBJECTMANAGER_H
#define GAMEOBJECTMANAGER_H

#include "SFML/Graphics.hpp"

#include "visiblegameobject.h"
#include <string>
#include <map>

class GameObjectManager
{
public:
    GameObjectManager();
    ~GameObjectManager();

    void add(std::string name, VisibleGameObject* gameObject);
    void remove(std::string name);
    int getObjectCount() const;
    VisibleGameObject* get(std::string name) const;

    void updateAll(); //testing
    void drawAll(sf::RenderWindow& window);

private:
    std::map<std::string, VisibleGameObject*> _gameObjects;

    sf::Clock clock;

    struct GameObjectDeallocator
    {
        void operator()(const std::pair<std::string, VisibleGameObject*>& p) const
        {
            delete p.second;
        }
    };
};

#endif // GAMEOBJECTMANAGER_H
