#include "MainMenuState.h"

#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/MainMenuView/MainMenuView.h"

void SnakeGame::MainMenuState::onActive(Game& game)
{
}

void SnakeGame::MainMenuState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Up) || isKeyPressed(sf::Keyboard::W))
    {
        SelectPrevMainMenuOption();
    }

    if (isKeyPressed(sf::Keyboard::Down) || isKeyPressed(sf::Keyboard::S))
    {
        SelectNextMainMenuOption();
    }

    if (isKeyPressed(sf::Keyboard::Enter) || isKeyPressed(sf::Keyboard::Return))
    {
        HandleMainMenuSelection(game);
    }
}

void SnakeGame::MainMenuState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawMainMenu(game, window);
}

void SnakeGame::MainMenuState::onInactive(Game& game)
{
}
