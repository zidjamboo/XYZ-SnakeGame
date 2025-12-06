#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{

    struct Game
    {

    };

    void InitGame(Game& game);
    void UpdateGame(Game& game);
    void DrawGame(Game& game, sf::RenderWindow& window);
}
