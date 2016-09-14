#ifndef MAINMENU_H
#define MAINMENU_H

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

class MainMenu
{
public:
    enum MenuResult { Nothing, Exit, Play, Options, Scoreboard };

    struct MenuItem
    {
    public:
        sf::Rect<int> rect;
        MenuResult action;
    };

    MenuResult show(sf::RenderWindow& window);

private:
    MenuResult getMenuResponse(sf::RenderWindow& window);
    MenuResult handleClick(int x, int y);
    std::list<MenuItem> _menuItems;
};

#endif // MAINMENU_H
