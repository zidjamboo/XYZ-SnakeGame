#pragma once
#include <cstdint>
#include <SFML/Graphics.hpp>

#include "DifficultyScreenState.h"
#include "GameFinishState.h"
#include "MainMenuState.h"
#include "PauseState.h"
#include "PlayingState.h"
#include "SaveRecordInputName.h"
#include "SaveRecordState.h"

namespace SnakeGame
{
    struct Game;
    struct GameState
    {
        enum class State : std::uint8_t
        {
            MAIN_MENU,
            DIFFICULTY_SCREEN,
            PAUSE,
            PLAYING,
            SAVE_RECORD,
            SAVE_RECORD_ENTER_NAME,
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
            else if (state == State::DIFFICULTY_SCREEN)
            {
                DifficultyScreenState::onActive(game);
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
            else if (state == State::SAVE_RECORD_ENTER_NAME)
            {
                SaveRecordEnterName::onActive(game);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onActive(game);
            }
        }

        void onUpdate(Game& game, const float& deltaTime, sf::Event& event) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onUpdate(game, deltaTime, event);
            }
            else if (state == State::DIFFICULTY_SCREEN)
            {
                DifficultyScreenState::onUpdate(game, deltaTime, event);
            }
            else if (state == State::PAUSE)
            {
                PauseState::onUpdate(game, deltaTime, event);
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onUpdate(game, deltaTime, event);
            }
            else if (state == State::SAVE_RECORD)
            {
                SaveRecordState::onUpdate(game, deltaTime, event);
            }
            else if (state == State::SAVE_RECORD_ENTER_NAME)
            {
                SaveRecordEnterName::onUpdate(game, deltaTime, event);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onUpdate(game, deltaTime, event);
            }
        }

        void onDraw(Game& game, sf::RenderWindow& window) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onDraw(game, window);
            }
            else if (state == State::DIFFICULTY_SCREEN)
            {
                DifficultyScreenState::onDraw(game, window);
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
            else if (state == State::SAVE_RECORD_ENTER_NAME)
            {
                SaveRecordEnterName::onDraw(game, window);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onDraw(game, window);
            }
        }

        void onInactive(Game& game) const
        {
            if (state == State::MAIN_MENU)
            {
                MainMenuState::onInactive(game);
            }
            else if (state == State::DIFFICULTY_SCREEN)
            {
                DifficultyScreenState::onInactive(game);
            }
            else if (state == State::PAUSE)
            {
                PauseState::onInactive(game);
            }
            else if (state == State::PLAYING)
            {
                PlayingState::onInactive(game);
            }
            else if (state == State::SAVE_RECORD)
            {
                SaveRecordState::onInactive(game);
            }
            else if (state == State::SAVE_RECORD_ENTER_NAME)
            {
                SaveRecordEnterName::onInactive(game);
            }
            else if (state == State::GAME_FINISH)
            {
                GameFinishState::onInactive(game);
            }
        }
    };

    void PushGameState(Game& game, GameState state);
    GameState TopGameState(Game& game);
    void PopGameState(Game& game);
    void ClearGameStateStack(Game& game);
}
