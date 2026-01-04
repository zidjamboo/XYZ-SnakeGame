#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Fonts
    {
        sf::Font robotoRegular;
        sf::Font robotoBold;
    };

    struct Game;

    void InitFonts(Game& game);
}
