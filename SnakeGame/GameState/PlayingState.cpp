#include "PlayingState.h"

#include "../Game/Game.h"
#include "../Utils/KeyboardHelper.h"

void SnakeGame::PlayingState::onActive()
{
}

void SnakeGame::PlayingState::onUpdate(Game& game)
{
    if (isKeyPressed(sf::Keyboard::Escape))
    {
        PushGameState(game, GameState::State::PAUSE);
    }
}

void SnakeGame::PlayingState::onDraw(Game& game, sf::RenderWindow& window)
{
    window.draw(game.background.sprite);
}

void SnakeGame::PlayingState::onInactive()
{
}
