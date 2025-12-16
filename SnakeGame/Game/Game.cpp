#include "Game.h"

#include "../Field/Field.h"
#include "../View/ScoreTopPanel/ScoreTopPanel.h"

namespace SnakeGame
{
    void InitGame(Game& game)
    {
        game.stateStack.emplace(GameState::State::MAIN_MENU);

        InitBackground(game);
        InitScoreTopPanel();
    }

    void RestartGame(Game& game)
    {
        InitField();
        InitSnake(game.snake);
        InitApple(game.apple);
        ReplaceApple(game.apple);
    }

    void UpdateGame(Game& game, const float& deltaTime)
    {
        TopGameState(game).onUpdate(game, deltaTime);
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
