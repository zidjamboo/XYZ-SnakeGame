#include "Game.h"

namespace SnakeGame
{
    void InitGame(Game& game)
    {
        game.stateStack.emplace(GameState::State::MAIN_MENU);
    }

    void UpdateGame(Game& game)
    {
        TopGameState(game).onUpdate(game);
    }

    void DrawGame(Game& game, sf::RenderWindow& window)
    {
        window.clear();
        TopGameState(game).onDraw(game, window);
        window.display();
    }

    void PushGameState(Game& game, GameState state)
    {
        game.stateStack.emplace(state);
        state.onActive();
    }

    GameState TopGameState(Game& game)
    {
        return game.stateStack.top();
    }

    void PopGameState(Game& game)
    {
        GameState& state = game.stateStack.top();
        game.stateStack.pop();
        state.onInactive();
    }
}
