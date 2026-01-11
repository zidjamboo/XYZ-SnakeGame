#pragma once
#include <cstdint>

namespace SnakeGame
{
    struct GameMode
    {
        enum class Difficulty : uint8_t
        {
            EASY,
            EASY_MID,
            MID,
            MID_HARD,
            HARD
        };

        Difficulty difficulty;

        GameMode(Difficulty difficulty) : difficulty(difficulty) {}
    };
}
