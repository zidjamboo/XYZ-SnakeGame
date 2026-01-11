#include "SaveRecordState.h"

#include "../../Utils/KeyboardHelper.h"
#include "../../View/SaveRecordQuestionPopup/SaveRecordQuestionPopup.h"

void SnakeGame::SaveRecordState::onActive(Game& game)
{
}

void SnakeGame::SaveRecordState::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Up) || isKeyPressed(sf::Keyboard::Down) ||
        isKeyPressed(sf::Keyboard::W) || isKeyPressed(sf::Keyboard::S))
    {
        SwitchRecordQuestionOption();
    }

    if (isKeyPressed(sf::Keyboard::Enter) || isKeyPressed(sf::Keyboard::Return) || isKeyPressed(sf::Keyboard::Space))
    {
        HandleSelectedOptionClick(game);
    }
}

void SnakeGame::SaveRecordState::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawRecordQuestionPopup(game, window);
}

void SnakeGame::SaveRecordState::onInactive(Game& game)
{
}
