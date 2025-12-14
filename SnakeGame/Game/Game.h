#pragma once
#include <list>
#include <stack>
#include <SFML/Graphics.hpp>

#include "../GameState/GameState.h"
#include "../View/BackGround.h"
#include "../Actor/Snake/Snake.h"

namespace SnakeGame
{

    struct Game
    {
        std::stack<GameState> stateStack;

        Background background;

        Snake snake;
    };

    void InitGame(Game& game);
    void RestartGame(Game& game);
    void UpdateGame(Game& game, const float& deltaTime);
    void DrawGame(Game& game, sf::RenderWindow& window);

    void PushGameState(Game& game, GameState state);
    GameState TopGameState(Game& game);
    void PopGameState(Game& game);
}
