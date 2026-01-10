#include "MainMenuState.h"

#include "../Game.h"
#include "../../View/MainMenuView/MainMenuView.h"

void SnakeGame::MainMenuState::onActive(Game& game)
{
}

void SnakeGame::MainMenuState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        PushGameState(game, GameState::State::PLAYING);
    }
}

void SnakeGame::MainMenuState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawMainMenu(game, window);
}

void SnakeGame::MainMenuState::onInactive()
{
}
