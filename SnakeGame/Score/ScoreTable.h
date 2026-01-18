#pragma once
#include <vector>

#include <SFML/System/String.hpp>

namespace SnakeGame
{
    struct Score
    {
        unsigned int value = 0;
    };

    struct ScoreRow
    {
        sf::String userName;
        Score score;

        bool operator>(const ScoreRow& other) const
        {
            return score.value > other.score.value;
        }
    };

    struct ScoreTable
    {
        std::vector<ScoreRow> rows;
    };
}
