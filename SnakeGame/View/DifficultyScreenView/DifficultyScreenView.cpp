#include "DifficultyScreenView.h"

#include "../../Game/Game.h"
#include "../BasePopupContainer/BasePopupContainer.h"
#include "../../Constants.h"

namespace
{
    enum class SelectedOption : std::uint8_t
    {
        EASY,
        EASY_MID,
        MID,
        MID_HARD,
        HARD
    };

    constexpr SelectedOption optionsArray[] = {
        SelectedOption::EASY,
        SelectedOption::EASY_MID,
        SelectedOption::MID,
        SelectedOption::MID_HARD,
        SelectedOption::HARD
    };

    SelectedOption selectedOption = SelectedOption::EASY;

    void DrawMenuOption(const wchar_t* str, SelectedOption option, const float& yPositon, const SnakeGame::Fonts& fonts, sf::RenderWindow& window)
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
        text.setFillColor(color);
        text.setFont(fonts.robotoRegular);
        text.setCharacterSize(24);
        text.setString(str);
        text.setPosition({(SCREEN_WIDTH - text.getGlobalBounds().width) / 2, yPositon});

        window.draw(text);
    }
}

void SnakeGame::DrawScreenDifficulty(const Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Уроверь сложности", game.fonts, window);
    DrawMenuOption(L"Лекгий",  SelectedOption::EASY, 200.f, game.fonts, window);
    DrawMenuOption(L"Тяжелее легкого", SelectedOption::EASY_MID, 240.f, game.fonts, window);
    DrawMenuOption(L"Средний", SelectedOption::MID, 280.f, game.fonts, window);
    DrawMenuOption(L"Легче тяжелого", SelectedOption::MID_HARD, 320.f, game.fonts, window);
    DrawMenuOption(L"Тяжелый", SelectedOption::HARD, 360.f, game.fonts, window);
}

void SnakeGame::SelectNextDifficultyOption()
{
    int index = static_cast<int>(selectedOption) + 1;
    if (index > 4)
    {
        index = 0;
    }

    selectedOption = optionsArray[index];
}

void SnakeGame::SelectPrevDifficultyOption()
{
    int index = static_cast<int>(selectedOption) - 1;
    if (index < 0)
    {
        index = 4;
    }

    selectedOption = optionsArray[index];
}

void SnakeGame::HandleDifficultyOptionClick(Game& game)
{
    if (selectedOption == SelectedOption::EASY)
    {
        game.gameMode = GameMode::Difficulty::EASY;
    }
    else if (selectedOption == SelectedOption::EASY_MID)
    {
        game.gameMode = GameMode::Difficulty::EASY_MID;
    }
    else if (selectedOption == SelectedOption::MID)
    {
        game.gameMode = GameMode::Difficulty::MID;
    }
    else if (selectedOption == SelectedOption::MID_HARD)
    {
        game.gameMode = GameMode::Difficulty::MID_HARD;
    }
    else if (selectedOption == SelectedOption::HARD)
    {
        game.gameMode = GameMode::Difficulty::HARD;
    }
}

void SnakeGame::SetDefaultDifficulty(const GameMode& gameMode)
{
    if (gameMode.difficulty == GameMode::Difficulty::EASY)
    {
        selectedOption = SelectedOption::EASY;
    }
    else if (gameMode.difficulty == GameMode::Difficulty::EASY_MID)
    {
        selectedOption = SelectedOption::EASY_MID;
    }
    else if (gameMode.difficulty == GameMode::Difficulty::MID)
    {
        selectedOption = SelectedOption::MID;
    }
    else if (gameMode.difficulty == GameMode::Difficulty::MID_HARD)
    {
        selectedOption = SelectedOption::MID_HARD;
    }
    else if (gameMode.difficulty == GameMode::Difficulty::HARD)
    {
        selectedOption = SelectedOption::HARD;
    }
}
