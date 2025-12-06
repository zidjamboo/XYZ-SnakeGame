#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayingState.h"

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

        void onActive() const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onActive();
            }
            else if (state == State::PAUSE)
            {
                PauseState::onActive();
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onActive();
            }
            else if (state == State::GAME_FINISH)
            {

            }
        }

        void onUpdate(Game& game) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onUpdate(game);
            }
            else if (state == State::PAUSE)
            {
                PauseState::onUpdate(game);
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onUpdate(game);
            }
            else if (state == State::GAME_FINISH)
            {

            }
        }

        void onDraw(Game& game, sf::RenderWindow& window) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onDraw(game, window);
            }
            else if (state == State::PAUSE)
            {
                PauseState::onDraw(game, window);
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onDraw(game, window);
            }
            else if (state == State::GAME_FINISH)
            {

            }
        }

        void onInactive() const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onInactive();
            }
            else if (state == State::PAUSE)
            {
                PauseState::onInactive();
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onInactive();
            }
            else if (state == State::GAME_FINISH)
            {

            }
        }
    };
}
