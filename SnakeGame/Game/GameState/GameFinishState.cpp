#include "GameFinishState.h"

#include "../Game.h"
#include "../../View/FinishGamePopup/FinishGamePopup.h"

void SnakeGame::GameFinishState::onActive()
{
}

void SnakeGame::GameFinishState::onUpdate(Game& game, const float& deltaTime)
{
}

void SnakeGame::GameFinishState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawFinishGamePopup(game, window);
}

void SnakeGame::GameFinishState::onInactive()
{
}
