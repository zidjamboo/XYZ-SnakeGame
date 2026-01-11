#pragma once
#include <SFML/Graphics.hpp>

#include "../../Game/GameMode/GameMode.h"

namespace SnakeGame
{
    struct Game;
    void DrawScreenDifficulty(const Game& game, sf::RenderWindow& window);
    void SelectNextDifficultyOption();
    void SelectPrevDifficultyOption();
    void HandleDifficultyOptionClick(Game& game);
    void SetDefaultDifficulty(const GameMode& gameMode);
}
