#include "PauseState.h"

#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"

void SnakeGame::PauseState::onActive(Game& game)
{
}

void SnakeGame::PauseState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Escape))
    {
        PopGameState(game);
    }
}

void SnakeGame::PauseState::onDraw(Game& game, sf::RenderWindow& window)
{
    sf::RectangleShape rect;
    rect.setPosition(100.f, 100.f);
    rect.setSize({50.f, 50.f});
    rect.setFillColor(sf::Color::Yellow);

    window.draw(rect);
}

void SnakeGame::PauseState::onInactive(Game& game)
{
}
