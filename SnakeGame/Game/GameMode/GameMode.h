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

        float GetSpeedModifier() const
        {
            if (difficulty == Difficulty::EASY)
            {
                return 1.f;
            }

            if (difficulty == Difficulty::EASY_MID)
            {
                return 0.8f;
            }

            if (difficulty == Difficulty::MID)
            {
                return 0.6f;
            }

            if (difficulty == Difficulty::MID_HARD)
            {
                return 0.4f;
            }

            if (difficulty == Difficulty::HARD)
            {
                return 0.2f;
            }

            return 0.f;
        }

        int GetScoreModifier() const
        {
            if (difficulty == Difficulty::EASY)
            {
                return 2;
            }

            if (difficulty == Difficulty::EASY_MID)
            {
                return 4;
            }

            if (difficulty == Difficulty::MID)
            {
                return 6;
            }

            if (difficulty == Difficulty::MID_HARD)
            {
                return 8;
            }

            if (difficulty == Difficulty::HARD)
            {
                return 10;
            }

            return 0;
        }

        int GetLengthModifier() const
        {
            if (difficulty == Difficulty::EASY || difficulty == Difficulty::EASY_MID)
            {
                return 1;
            }

            if (difficulty == Difficulty::MID || difficulty == Difficulty::MID_HARD)
            {
                return 2;
            }

            if (difficulty == Difficulty::HARD)
            {
                return 3;
            }

            return 0;
        }
    };
}
