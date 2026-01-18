#pragma once
#include "../Fonts/Fonts.h"
#include "../../Score/ScoreTable.h"

namespace SnakeGame
{
    struct Game;
    void DrawRecords(
        const Fonts& fonts,
        ScoreTable& scoreTable,
        const int& maxRows,
        const float& startYPosition,
        sf::RenderWindow& window
    );
}
