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
    sf::RectangleShape rect;
    rect.setPosition(50.f, 50.f);
    rect.setSize({50.f, 50.f});
    rect.setFillColor(sf::Color::Green);

    window.draw(rect);
}

void SnakeGame::PlayingState::onInactive()
{
}
