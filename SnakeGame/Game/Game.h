#pragma once
#include <stack>
#include <SFML/Graphics.hpp>

#include "GameState/GameState.h"
#include "../View/Background/BackGround.h"
#include "../Actor/Snake/Snake.h"
#include "../Actor/Apple/Apple.h"
#include "../Score/Score.h"
#include "../View/Fonts/Fonts.h"

namespace SnakeGame
{
    struct Game
    {
        std::stack<GameState> stateStack;

        Background background;

        Snake snake;
        Apple apple;

        Score score;

        Fonts fonts;
    };

    void InitGame(Game& game);
    void RestartGame(Game& game);
    void UpdateGame(Game& game, const float& deltaTime, sf::Event& event);
    void DrawGame(Game& game, sf::RenderWindow& window);
}
