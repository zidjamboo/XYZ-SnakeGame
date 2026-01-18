#include "SaveRecordQuestionPopup.h"

#include "../../Constants.h"
#include "../../Game/Game.h"
#include "../Fonts/Fonts.h"

namespace
{
    enum class SelectedOption : std::uint8_t
    {
        YES, NO
    };

    SelectedOption selectedOption = SelectedOption::NO;

    void DrawPopupBackground(sf::RenderWindow& window)
    {
        sf::RectangleShape border;
        sf::Vector2f borderSize = {300.f, 150.f};
        sf::Vector2f borderPosition = {(SCREEN_WIDTH - borderSize.x) / 2, 150.f};
        border.setFillColor(sf::Color::White);
        border.setSize(borderSize);
        border.setPosition(borderPosition);

        sf::RectangleShape background;
        sf::Vector2f backgroundSize = {borderSize.x - 20.f, borderSize.y - 20.f};
        sf::Vector2f backgroundPosition = {borderPosition.x + 10.f, borderPosition.y + 10.f};
        background.setFillColor(sf::Color::Black);
        background.setSize(backgroundSize);
        background.setPosition(backgroundPosition);

        window.draw(border);
        window.draw(background);
    }

    void DrawTitle(const SnakeGame::Fonts& fonts, sf::RenderWindow& window)
    {
        sf::Text title;
        title.setFont(fonts.robotoBold);
        title.setFillColor(sf::Color::White);
        title.setCharacterSize(24);
        title.setString(L"Ввести имя");
        title.setPosition({(SCREEN_WIDTH - title.getGlobalBounds().width) / 2, 170.f});

        window.draw(title);
    }

    void DrawOption(
        const SelectedOption& option,
        const wchar_t* str,
        const float& yPosition,
        const SnakeGame::Fonts& fonts,
        sf::RenderWindow& window)
    {
        sf::Color color;
        if (selectedOption == option)
        {
            color = sf::Color::Green;
        }
        else
        {
            color = sf::Color::White;
        }

        sf::Text text;
        text.setFont(fonts.robotoRegular);
        text.setCharacterSize(20);
        text.setFillColor(color);
        text.setString(str);
        text.setPosition({(SCREEN_WIDTH - text.getGlobalBounds().width) / 2, yPosition});

        window.draw(text);
    }
}

void SnakeGame::DrawRecordQuestionPopup(Game& game, sf::RenderWindow& window)
{
    DrawPopupBackground(window);
    DrawTitle(game.fonts, window);
    DrawOption(
        SelectedOption::NO,
        L"Нет",
        210.f,
        game.fonts,
        window
    );
    DrawOption(
        SelectedOption::YES,
        L"Да",
        240.f,
        game.fonts,
        window
    );
}

void SnakeGame::SwitchRecordQuestionOption()
{
    if (selectedOption == SelectedOption::YES)
    {
        selectedOption = SelectedOption::NO;
    }
    else
    {
        selectedOption = SelectedOption::YES;
    }
}

void SnakeGame::HandleSelectedRecordQuestionOptionClick(Game& game)
{
    if (selectedOption == SelectedOption::NO)
    {
        PushGameState(game, GameState::State::GAME_FINISH);
    }
    else if (selectedOption == SelectedOption::YES)
    {
        PushGameState(game, GameState::State::SAVE_RECORD_ENTER_NAME);
    }
}

void SnakeGame::SelectDefaultRecordQuestionOption()
{
    selectedOption = SelectedOption::NO;
}
