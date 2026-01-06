#include "SaveRecordState.h"

#include "../../View/SaveRecordQuestionPopup/SaveRecordQuestionPopup.h"

void SnakeGame::SaveRecordState::onActive(Game& game)
{
}

void SnakeGame::SaveRecordState::onUpdate(Game& game, const float& deltaTime)
{
}

void SnakeGame::SaveRecordState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawRecordQuestionPopup(game, window);
}

void SnakeGame::SaveRecordState::onInactive()
{
}
