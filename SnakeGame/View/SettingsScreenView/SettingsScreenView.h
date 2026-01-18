#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    void DrawSettingsScreenView(Game& game, sf::RenderWindow& window);
    void SwitchSettingsScreenOption();
    void HandleSettingsScreenOptionClick(Game& game);
}
