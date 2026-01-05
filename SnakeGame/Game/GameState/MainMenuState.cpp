#include "MainMenuState.h"

#include "../Game.h"

void SnakeGame::MainMenuState::onActive(Game& game)
{
}

void SnakeGame::MainMenuState::onUpdate(Game& game, const float& deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        PushGameState(game, GameState::State::PLAYING);
    }
}

void SnakeGame::MainMenuState::onDraw(Game& game, sf::RenderWindow& window)
{
    sf::RectangleShape rect;
    rect.setPosition(0.f, 0.f);
    rect.setSize({50.f, 50.f});
    rect.setFillColor(sf::Color::Red);

    window.draw(rect);
}

void SnakeGame::MainMenuState::onInactive()
{
}
