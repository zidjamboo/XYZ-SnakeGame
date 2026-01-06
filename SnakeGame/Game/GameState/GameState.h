#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

#include "GameFinishState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayingState.h"
#include "SaveRecordState.h"

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
            SAVE_RECORD,
            GAME_FINISH
        };

        State state;

        GameState(State state) : state(state) {}

        void onActive(Game& game) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onActive(game);
            }
            else if (state == State::PAUSE)
            {
                PauseState::onActive(game);
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onActive(game);
            }
            else if (state == State::SAVE_RECORD)
            {
                SaveRecordState::onActive(game);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onActive(game);
            }
        }

        void onUpdate(Game& game, const float& deltaTime) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onUpdate(game, deltaTime);
            }
            else if (state == State::PAUSE)
            {
                PauseState::onUpdate(game, deltaTime);
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onUpdate(game, deltaTime);
            }
            else if (state == State::SAVE_RECORD)
            {
                SaveRecordState::onUpdate(game, deltaTime);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onUpdate(game, deltaTime);
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
            else if (state == State::SAVE_RECORD)
            {
                SaveRecordState::onDraw(game, window);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onDraw(game, window);
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
            else if (state == State::SAVE_RECORD)
            {
                SaveRecordState::onInactive();
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onInactive();
            }
        }
    };

    void PushGameState(Game& game, GameState state);
    GameState TopGameState(Game& game);
    void PopGameState(Game& game);
    void ClearGameStateStack(Game& game);
}
