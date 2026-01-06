#include "SaveRecordInputName.h"

#include "../Game.h"
#include "../../Utils/KeyboardHelper.h"
#include "../../View/SaveRecordEnterName/SaveRecordInputNameView.h"

void SnakeGame::SaveRecordEnterName::onActive(Game& game)
{
}

void SnakeGame::SaveRecordEnterName::onUpdate(Game& game, const float& deltaTime, sf::Event& event)
{
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

void SnakeGame::SaveRecordEnterName::onInactive()
{
}
