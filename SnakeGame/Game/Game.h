#pragma once
#include <stack>
#include <SFML/Graphics.hpp>

#include "GameState/GameState.h"
#include "../View/Background/BackGround.h"
#include "../Actor/Snake/Snake.h"
#include "../Actor/Apple/Apple.h"
#include "../Score/ScoreTable.h"
#include "../Sound/SoundResources.h"
#include "../Sound/SoundSettings.h"
#include "../View/Fonts/Fonts.h"
#include "GameMode/GameMode.h"
#include "../Texture/Textures.h"

namespace SnakeGame
{
    struct Game
    {
        std::stack<GameState> stateStack;

        Background background;
        Textures textures;

        Snake snake;
        Apple apple;

        ScoreTable savedScores;
        Score currentScore;

        GameMode gameMode = GameMode::Difficulty::EASY;

        SoundSettings soundSettings;
        SoundResources soundResources;

        Fonts fonts;
    };

    void InitGame(Game& game);
    void RestartGame(Game& game);
    void UpdateGame(Game& game, const float& deltaTime, sf::Event& event);
    void DrawGame(Game& game, sf::RenderWindow& window);
}
