#include "SaveRecordInputNameState.h"

#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/SaveRecordEnterName/SaveRecordInputNameView.h"

void SnakeGame::SaveRecordEnterName::onActive(Game& game)
{
}

void SnakeGame::SaveRecordEnterName::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
    if (isKeyPressed(sf::Keyboard::Enter) || isKeyPressed(sf::Keyboard::Return))
    {
        ScoreRow scoreRow;
        scoreRow.userName = SaveRecordEnterNameGetName();
        scoreRow.score = game.currentScore;
        game.savedScores.rows.push_back(scoreRow);
        PushGameState(game, GameState::State::GAME_FINISH);
    }

    if (event.type == sf::Event::TextEntered)
    {
        sf::Uint32 unicode = event.text.unicode;
        if (isApplyTextEnteredUnicode(unicode))
        {
            sf::String str = sf::String::fromUtf32(&unicode, &unicode + 1);
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
            {
                SaveRecordEnterNameAppendString(str);
            } else
            {
                SaveRecordEnterNameEraseLastCharacter();
            }
        }
    }
}

void SnakeGame::SaveRecordEnterName::onDraw(Game& game, sf::RenderWindow& window)
{
    DrawSaveRecordInputNameView(game.fonts, window);
}

void SnakeGame::SaveRecordEnterName::onInactive(Game& game)
{
    SaveRecordEnterNameClear();
}
