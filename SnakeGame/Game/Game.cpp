#include "Game.h"

namespace SnakeGame
{
    void InitGame(Game& game)
    {
        game.stateStack.emplace(GameState::State::MAIN_MENU);
    }

    void UpdateGame(Game& game)
    {
    }

    void DrawGame(Game& game, sf::RenderWindow& window)
    {
        window.clear();
        window.display();
    }

    void PushGameState(Game& game, GameState& state)
    {
        game.stateStack.emplace(state);
        state.onActive();
    }

    void PopGameState(Game& game)
    {
        GameState& state = game.stateStack.top();
        game.stateStack.pop();
        state.onDeactive();
    }
}
