#pragma once
#include <SFML/Graphics.hpp>
#include "../Fonts/Fonts.h"

namespace SnakeGame
{
    void DrawSaveRecordInputNameView(const Fonts& fonts, sf::RenderWindow& window);
    void SaveRecordEnterNameAppendString(sf::String& str);
    void SaveRecordEnterNameEraseLastCharacter();
    sf::String SaveRecordEnterNameGetName();
    void SaveRecordEnterNameClear();
}
