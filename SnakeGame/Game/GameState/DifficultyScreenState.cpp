#include "DifficultyScreenState.h"

#include "GameState.h"
#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/DifficultyScreenView/DifficultyScreenView.h"

void SnakeGame::DifficultyScreenState::onActive(Game& game)
{
    SetDefaultDifficulty(game.gameMode);
}

void SnakeGame::DifficultyScreenState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Escape) || isKeyPressed(sf::Keyboard::B))
    {
        PopGameState(game);
    }

    if (isKeyPressed(sf::Keyboard::Down) || isKeyPressed(sf::Keyboard::S))
    {
        SelectNextDifficultyOption();
    }

    if (isKeyPressed(sf::Keyboard::Up) || isKeyPressed(sf::Keyboard::W))
    {
        SelectPrevDifficultyOption();
    }

    if (isKeyPressed(sf::Keyboard::Enter) || isKeyPressed(sf::Keyboard::Return))
    {
        HandleDifficultyOptionClick(game);
        PopGameState(game);
    }
}

void SnakeGame::DifficultyScreenState::onDraw(const Game& game, sf::RenderWindow& window)
{
    DrawScreenDifficulty(game, window);
}

void SnakeGame::DifficultyScreenState::onInactive(Game& game)
{
}
