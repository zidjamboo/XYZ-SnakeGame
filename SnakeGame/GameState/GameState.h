#pragma once
#include <cstdint>

namespace SnakeGame
{
    struct Game;
    struct GameState
    {
        enum class State : std::uint8_t
        {
            MAIN_MENU,
            PAUSE,
            PLAYING,
            GAME_FINISH
        };

        State state;

        GameState(State state) : state(state) {}

        void onActive()
        {
            if (state == State::MAIN_MENU)
            {

            }
            else if (state == State::PAUSE)
            {

            }
            else if (state == State::PLAYING)
            {

            }
            else if (state == State::GAME_FINISH)
            {

            }
        }

        void onUpdate(Game& game)
        {
            if (state == State::MAIN_MENU)
            {

            }
            else if (state == State::PAUSE)
            {

            }
            else if (state == State::PLAYING)
            {

            }
            else if (state == State::GAME_FINISH)
            {

            }
        }

        void onDraw(Game& game)
        {
            if (state == State::MAIN_MENU)
            {

            }
            else if (state == State::PAUSE)
            {

            }
            else if (state == State::PLAYING)
            {

            }
            else if (state == State::GAME_FINISH)
            {

            }
        }

        void onDeactive()
        {
            if (state == State::MAIN_MENU)
            {

            }
            else if (state == State::PAUSE)
            {

            }
            else if (state == State::PLAYING)
            {

            }
            else if (state == State::GAME_FINISH)
            {

            }
        }
    };
}
