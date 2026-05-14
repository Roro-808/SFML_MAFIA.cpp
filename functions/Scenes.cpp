#include "func.cpp"
#include <iostream>
#include <SFML/Graphics.hpp>

enum Scenes {
    Menu,
    Settings,
    ChooseServer,
    Lobby,
    Game
};

Scenes CurrentScene = Menu;

static struct {
    sf::Font font;
    sf::Text title;
    sf::RectangleShape playButton;
    sf::Text playText;
    sf::RectangleShape settingsButton;
    sf::Text settingsText;
    sf::RectangleShape exitButton;
    sf::Text exitText;
    int selectedButton;
} menu;

