#include "RecordScreenState.h"

#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/RecordScreenView/RecordScreenVIew.h"

void SnakeGame::RecordScreenState::onActive(Game& game)
{
}

void SnakeGame::RecordScreenState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Escape) || isKeyPressed(sf::Keyboard::B))
    {
        PopGameState(game);
    }
}

void SnakeGame::RecordScreenState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawRecordScreenView(game, window);
}

void SnakeGame::RecordScreenState::onInactive(Game& game)
{
}
