#include "mainmenu.h"

MainMenu::MenuResult MainMenu::show(sf::RenderWindow &window)
{
    sf::Texture texture;
    texture.loadFromFile("images/mainmenu2.png");
    sf::Sprite sprite(texture);

    //Setup clickable regions

    //Play menu item
    MenuItem playButton;
    playButton.rect.top = 406;
    playButton.rect.left = 153;
    playButton.rect.width = 402;
    playButton.rect.height = 98;
    playButton.action = Play;

    //Exit menu item
    MenuItem exitButton;
    exitButton.rect.top = 613;
    exitButton.rect.left = 720;
    exitButton.rect.width = 383;
    exitButton.rect.height = 122;
    exitButton.action = Exit;

    //Options menu item
    MenuItem optionsButton;
    optionsButton.rect.top = 607;
    optionsButton.rect.left = 176;
    optionsButton.rect.width = 383;
    optionsButton.rect.height = 120;
    optionsButton.action = Options;

    //Scores menu item
    MenuItem scoresButton;
    scoresButton.rect.top = 393;
    scoresButton.rect.left = 795;
    scoresButton.rect.width = 442;
    scoresButton.rect.height = 106;
    scoresButton.action = Scoreboard;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);
    _menuItems.push_back(optionsButton);
    _menuItems.push_back(scoresButton);

    window.draw(sprite);
    window.display();

    return getMenuResponse(window);
}

MainMenu::MenuResult MainMenu::handleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for (it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).rect;
        if (menuItemRect.top < y
            && menuItemRect.left < x
            && menuItemRect.top + menuItemRect.height > y
            && menuItemRect.left + menuItemRect.width > x)
        {
            return (*it).action;
        }
    }
    return Nothing;
}

MainMenu::MenuResult MainMenu::getMenuResponse(sf::RenderWindow &window)
{
    sf::Event menuEvent;

    while(true)
    {
        while(window.pollEvent(menuEvent))
        {
            if(menuEvent.type == sf::Event::MouseButtonPressed)
                return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            if(menuEvent.type == sf::Event::Closed)
                return Exit;
        }
    }
}
