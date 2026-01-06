#include "PlayingState.h"

#include "../Game.h"
#include "../../Actor/Snake/SnakeController.h"
#include "../../Field/Field.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/ScoreTopPanel/ScoreTopPanel.h"

namespace
{
    float tickCounter = 0.f;

    bool isTick(const float& deltaTime)
    {
        tickCounter += deltaTime;
        if (tickCounter >= 1.f)
        {
            tickCounter = tickCounter - 1.f;
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
}

void SnakeGame::PlayingState::onUpdate(Game& game, const float& deltaTime)
{
    if (isKeyPressed(sf::Keyboard::Escape))
    {
        PushGameState(game, GameState::State::PAUSE);
    }

    ChangeDirection(game.snake);

    if (!isTick(deltaTime))
    {
        return;
    }

    DoSnakeAction(game, [&game]()
    {
        ReplaceApple(game.apple);
        game.score.value++;
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

void SnakeGame::PlayingState::onInactive()
{
}
