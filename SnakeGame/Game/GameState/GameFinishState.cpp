#include "GameFinishState.h"

void SnakeGame::GameFinishState::onActive()
{
}

void SnakeGame::GameFinishState::onUpdate(Game& game, const float& deltaTime)
{
}

void SnakeGame::GameFinishState::onDraw(Game& game, sf::RenderWindow& window)
{
    sf::RectangleShape rect;
    rect.setSize({50.f, 50.f});
    rect.setPosition({0.f, 0.f});
    rect.setFillColor(sf::Color::White);

    window.draw(rect);
}

void SnakeGame::GameFinishState::onInactive()
{
}
