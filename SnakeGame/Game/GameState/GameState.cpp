#include "GameState.h"

#include "../../Actor/Snake/Snake.h"
#include "../Game.h"

void SnakeGame::PushGameState(Game& game, GameState state)
{
    game.stateStack.emplace(state);
    state.onActive(game);
}

SnakeGame::GameState SnakeGame::TopGameState(Game& game)
{
    return game.stateStack.top();
}

void SnakeGame::PopGameState(Game& game)
{
    GameState& state = game.stateStack.top();
    game.stateStack.pop();
    state.onInactive();
}

void SnakeGame::ClearGameStateStack(Game& game)
{
    while (!std::empty(game.stateStack))
    {
        PopGameState(game);
    }
}
