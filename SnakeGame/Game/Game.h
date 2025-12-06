#pragma once
#include <stack>
#include <SFML/Graphics.hpp>

#include "../GameState/GameState.h"

namespace SnakeGame
{

    struct Game
    {
        std::stack<GameState> stateStack;
    };

    void InitGame(Game& game);
    void UpdateGame(Game& game);
    void DrawGame(Game& game, sf::RenderWindow& window);

    void PushGameState(Game& game, GameState& state);
    void PopGameState(Game& game);
}
