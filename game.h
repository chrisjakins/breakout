#ifndef GAME_H
#define GAME_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "playerpaddle.h"
#include "gameobjectmanager.h"

class Game
{
public:
    const static int SCREEN_WIDTH = 1200;
    const static int SCREEN_HEIGHT = 1000;
    static void start();

    const static GameObjectManager& getGameObjectManager();

private:
    static bool isExiting();
    static void gameLoop();

    static void showMenu();

    enum GameState { Uninit, Paused, ShowingMenu, Options, Playing, Exiting };

    static GameState _gameState;
    static sf::RenderWindow _window;

    static GameObjectManager _gameObjectManager;
};

#endif // GAME_H
