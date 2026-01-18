#include "PlayingState.h"

#include "../Game.h"
#include "../../Actor/Snake/SnakeController.h"
#include "../../Field/Field.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/ScoreTopPanel/ScoreTopPanel.h"

namespace
{
    float tickCounter = 0.f;
    float startPauseTime;

    bool isTick(const SnakeGame::Game& game, const float& deltaTime)
    {
        const float speedModifier = game.gameMode.GetSpeedModifier();
        tickCounter += deltaTime;
        if (tickCounter >= speedModifier)
        {
            tickCounter = tickCounter - speedModifier;
            return true;
        }
        return false;
    }

    bool isGameOver(SnakeGame::Game& game)
    {
        bool isFieldOccupied = std::empty(SnakeGame::getFreePositions());
        bool isSnakeOutOfBounds = !SnakeGame::isPositionInBound(game.snake.head().position);
        bool isSnakeSelfCollide = SnakeGame::isSnakeSelfCollide(game.snake);

        return isFieldOccupied || isSnakeOutOfBounds || isSnakeSelfCollide;
    }
}

void SnakeGame::PlayingState::onActive(Game& game)
{
    RestartGame(game);
    startPauseTime = 1.f;
}

void SnakeGame::PlayingState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (startPauseTime > 0)
    {
        startPauseTime -= deltaTime;
        return;
    }

    if (isKeyPressed(sf::Keyboard::Escape))
    {
        PushGameState(game, GameState::State::PAUSE);
    }

    ChangeDirection(game.snake);

    if (!isTick(game, deltaTime))
    {
        return;
    }

    DoSnakeAction(game, [&game]()
    {
        ReplaceApple(game.apple);
        game.currentScore.value += game.gameMode.GetScoreModifier();
    });

    if (isGameOver(game))
    {
        PushGameState(game, GameState::State::SAVE_RECORD);
    }
}

void SnakeGame::PlayingState::onDraw(Game& game, sf::RenderWindow& window)
{
    window.draw(game.background.sprite);
    DrawSnake(game.snake, window);
    DrawApple(game.apple, window);
    DrawScoreTopPanel(game, window);
}

void SnakeGame::PlayingState::onInactive(Game& game)
{
}
