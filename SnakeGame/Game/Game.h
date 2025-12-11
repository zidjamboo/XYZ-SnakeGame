#pragma once
#include <stack>
#include <SFML/Graphics.hpp>

#include "../GameState/GameState.h"
#include "../View/BackGround.h"

namespace SnakeGame
{

    struct Game
    {
        std::stack<GameState> stateStack;

        Background background;
    };

    void InitGame(Game& game);
    void UpdateGame(Game& game);
    void DrawGame(Game& game, sf::RenderWindow& window);

    void PushGameState(Game& game, GameState state);
    GameState TopGameState(Game& game);
    void PopGameState(Game& game);
}
