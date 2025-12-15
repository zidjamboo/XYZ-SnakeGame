#include "PlayingState.h"

#include "../Game.h"
#include "../../Actor/Snake/SnakeController.h"
#include "../../Utils/KeyboardHelper.h"

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
}

void SnakeGame::PlayingState::onActive()
{
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
    });
}

void SnakeGame::PlayingState::onDraw(Game& game, sf::RenderWindow& window)
{
    window.draw(game.background.sprite);
    DrawSnake(game.snake, window);
    DrawApple(game.apple, window);
}

void SnakeGame::PlayingState::onInactive()
{
}
