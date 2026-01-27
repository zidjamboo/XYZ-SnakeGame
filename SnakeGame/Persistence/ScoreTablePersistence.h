#pragma once
#include "../Score/ScoreTable.h"

namespace SnakeGame
{
    struct Game;
    void SaveScoreTable(const ScoreTable& scoreTable);
    void LoadScoreTable(ScoreTable& scoreTable);
}
