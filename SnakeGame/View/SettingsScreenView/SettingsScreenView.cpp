#include "SettingsScreenView.h"

#include "../../Game/Game.h"
#include "../BasePopupContainer/BasePopupContainer.h"
#include "../../Constants.h"

namespace
{
    constexpr float SETTINGS_OPTION_WIDTH = 200.f;
    constexpr float START_X_POSITION = (SCREEN_WIDTH - SETTINGS_OPTION_WIDTH) / 2;

    enum class Option
    {
        MUSIC,
        SOUND
    };

    Option selectedOption = Option::MUSIC;

    void DrawSettingsOption(
        const wchar_t* optionName,
        const float& yPosition,
        const Option option,
        const bool& isChecked,
        const SnakeGame::Fonts& fonts,
        sf::RenderWindow& window
    )
    {
        sf::Color color;
        if (option == selectedOption)
        {
            color = sf::Color::Green;
        }
        else
        {
            color = sf::Color::White;
        }

        sf::Text optionText;
        optionText.setCharacterSize(24);
        optionText.setFillColor(color);
        optionText.setFont(fonts.robotoRegular);
        optionText.setString(optionName);
        optionText.setPosition(START_X_POSITION, yPosition);

        sf::RectangleShape checkBoxBorder;
        checkBoxBorder.setFillColor(color);
        checkBoxBorder.setSize({24.f, 24.f});
        checkBoxBorder.setPosition({
            START_X_POSITION + SETTINGS_OPTION_WIDTH - checkBoxBorder.getGlobalBounds().width,
            yPosition
        });

        sf::RectangleShape checkBox;
        checkBox.setFillColor(sf::Color::Black);
        checkBox.setSize({20.f, 20.f});
        checkBox.setPosition({
            checkBoxBorder.getPosition().x + (checkBoxBorder.getSize().x - checkBox.getSize().x) / 2,
            checkBoxBorder.getPosition().y + (checkBoxBorder.getSize().y - checkBox.getSize().y) / 2
        });



        window.draw(optionText);
        window.draw(checkBoxBorder);
        window.draw(checkBox);

        if (isChecked)
        {
            sf::CircleShape checkMark;
            checkMark.setRadius(8.f);
            checkMark.setFillColor(color);
            checkMark.setPosition({
                checkBox.getPosition().x + (checkBox.getSize().x - checkMark.getRadius() * 2) / 2,
                checkBox.getPosition().y + (checkBox.getSize().y - checkMark.getRadius() * 2) / 2
            });

            window.draw(checkMark);
        }
    }
}

void SnakeGame::DrawSettingsScreenView(Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Настройки", game.fonts, window);
    DrawSettingsOption(L"Музыка", 175.f, Option::MUSIC, game.soundSettings.isMusicEnabled, game.fonts, window);
    DrawSettingsOption(L"Звук", 215.f, Option::SOUND, game.soundSettings.isSoundEnabled, game.fonts, window);
}

void SnakeGame::SwitchSettingsScreenOption()
{
    if (selectedOption == Option::MUSIC)
    {
        selectedOption = Option::SOUND;
    } else
    {
        selectedOption = Option::MUSIC;
    }
}

void SnakeGame::HandleSettingsScreenOptionClick(Game& game)
{
    if (selectedOption == Option::MUSIC)
    {
        game.soundSettings.isMusicEnabled = !game.soundSettings.isMusicEnabled;
    }
    else if (selectedOption == Option::SOUND)
    {
        game.soundSettings.isSoundEnabled = !game.soundSettings.isSoundEnabled;
    }
}
