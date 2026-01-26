#pragma once
#include <SFML/Graphics.hpp>
#include "../../Types.h"

namespace SnakeGame
{
    struct Apple
    {
        FieldPosition position;
    };

    struct Game;
    void InitApple(Apple& apple);
    void ReplaceApple(Apple& apple);
    void DrawApple(const Game& game, sf::RenderWindow& window);
}
