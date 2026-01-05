#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;

    void SwitchSelectedFinishGameButton();
    void HandleSelectedFinishGameButtonClick(Game& game);
    void DrawFinishGamePopup(const Game& game, sf::RenderWindow& window);
}
