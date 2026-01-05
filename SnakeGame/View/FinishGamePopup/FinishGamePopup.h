#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;

    void SwitchSelectedFinishGameButton();
    void DrawFinishGamePopup(const Game& game, sf::RenderWindow& window);
}
