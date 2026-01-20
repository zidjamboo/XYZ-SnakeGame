#include "SettingsScreenState.h"

#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/SettingsScreenView/SettingsScreenView.h"

void SnakeGame::SettingsScreenState::onActive(Game& game)
{
}

void SnakeGame::SettingsScreenState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Up) || isKeyPressed(sf::Keyboard::Down) ||
        isKeyPressed(sf::Keyboard::W) || isKeyPressed(sf::Keyboard::S))
    {
        SwitchSettingsScreenOption();
        PlaySound(game, game.soundResources.menuHover);
    }

    if (isKeyPressed(sf::Keyboard::Enter) || (isKeyPressed(sf::Keyboard::Return)))
    {
        HandleSettingsScreenOptionClick(game);
    }

    if (isKeyPressed(sf::Keyboard::Escape) || isKeyPressed(sf::Keyboard::B))
    {
        PopGameState(game);
    }
}

void SnakeGame::SettingsScreenState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawSettingsScreenView(game, window);
}

void SnakeGame::SettingsScreenState::onInactive(Game& game)
{
}
