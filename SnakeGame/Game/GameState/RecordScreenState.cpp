#include "RecordScreenState.h"

#include "../Game.h"
#include "../../View/BasePopupContainer/BasePopupContainer.h"

void SnakeGame::RecordScreenState::onActive(Game& game)
{
}

void SnakeGame::RecordScreenState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
}

void SnakeGame::RecordScreenState::onDraw(const Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Таблица рекордов", game.fonts, window);
}

void SnakeGame::RecordScreenState::onInactive(Game& game)
{
}
