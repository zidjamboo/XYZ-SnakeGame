#include "GameFinishState.h"

#include "../Game.h"
#include "../../View/FinishGamePopup/FinishGamePopup.h"
#include "../../Utils/KeyboardHelper.h"

void SnakeGame::GameFinishState::onActive()
{
}

void SnakeGame::GameFinishState::onUpdate(Game& game, const float& deltaTime)
{
    if (isKeyPressed(sf::Keyboard::Up) || isKeyPressed(sf::Keyboard::Down))
    {
        SwitchSelectedFinishGameButton();
    }
}

void SnakeGame::GameFinishState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawFinishGamePopup(game, window);
}

void SnakeGame::GameFinishState::onInactive()
{
}
