#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Score;
    void InitScoreTopPanel();
    void DrawScoreTopPanel(const Score& score, sf::RenderWindow& window);
}
