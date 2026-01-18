#include "SaveRecordInputNameView.h"
#include "../Fonts/Fonts.h"

namespace
{
    sf::String name;
}

void SnakeGame::DrawSaveRecordInputNameView(const Fonts& fonts, sf::RenderWindow& window)
{
    sf::Text title;
    title.setFont(fonts.robotoBold);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(24);
    title.setString(L"Введите имя:");
    title.setPosition(240.f, 280.f);

    sf::Text text;
    text.setFont(fonts.robotoRegular);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    text.setString(name);
    text.setPosition(400.f, 280.f);

    window.draw(title);
    window.draw(text);
}

void SnakeGame::SaveRecordEnterNameAppendString(sf::String& str)
{
    name += str;
}

void SnakeGame::SaveRecordEnterNameEraseLastCharacter()
{
    if (name.getSize() > 1)
    {
        name.erase(name.getSize() - 1, 1);
    }
}

sf::String SnakeGame::SaveRecordEnterNameGetName()
{
    return name;
}

void SnakeGame::SaveRecordEnterNameClear()
{
    name.clear();
}
