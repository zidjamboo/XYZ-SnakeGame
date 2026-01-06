#include "GameFinishState.h"

#include "../Game.h"
#include "../../View/FinishGamePopup/FinishGamePopup.h"
#include "../../Utils/KeyboardHelper.h"

void SnakeGame::GameFinishState::onActive(Game& game)
{
}

void SnakeGame::GameFinishState::onUpdate(Game& game, const float& deltaTime, sf::Event& eve)
{
    if (isKeyPressed(sf::Keyboard::Up) || isKeyPressed(sf::Keyboard::Down))
    {
        SwitchSelectedFinishGameButton();
    }

    if (isKeyPressed(sf::Keyboard::Enter) || isKeyPressed(sf::Keyboard::Return) || isKeyPressed(sf::Keyboard::Space))
    {
        HandleSelectedFinishGameButtonClick(game);
    }
}

void SnakeGame::GameFinishState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawFinishGamePopup(game, window);
}

void SnakeGame::GameFinishState::onInactive()
{
}
