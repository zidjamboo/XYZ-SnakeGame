#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    void DrawMainMenu(const Game& game, sf::RenderWindow& window);
    void SelectNextMainMenuOption();
    void SelectPrevMainMenuOption();
    void HandleMainMenuSelection(Game& game);
}
