#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    void DrawRecordQuestionPopup(Game& game, sf::RenderWindow& window);
    void SwitchRecordQuestionOption();
    void HandleSelectedRecordQuestionOptionClick(Game& game);
    void SelectDefaultRecordQuestionOption();
}
