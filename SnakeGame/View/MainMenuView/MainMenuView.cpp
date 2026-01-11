#include "MainMenuView.h"

#include "../../Constants.h"
#include "../../Game/Game.h"
#include "../Fonts/Fonts.h"
#include "../BasePopupContainer/BasePopupContainer.h"

namespace
{
    enum class SelectedOption : uint8_t
    {
        START_GAME = 0,
        DIFFICULTY = 1,
        RECORDS = 2,
        SETTINGS = 3,
        EXIT = 4
    };

    constexpr SelectedOption optionsArray[] = {
        SelectedOption::START_GAME,
        SelectedOption::DIFFICULTY,
        SelectedOption::RECORDS,
        SelectedOption::SETTINGS,
        SelectedOption::EXIT
    };

    SelectedOption selectedOption = SelectedOption::START_GAME;

    SelectedOption GetOptionByIndex(const int& index)
    {
        return optionsArray[index];
    }

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

    void onStartGame(SnakeGame::Game& game)
    {
        SnakeGame::PushGameState(game, SnakeGame::GameState::State::PLAYING);
    }

    void onDifficulty(SnakeGame::Game& game)
    {
        SnakeGame::PushGameState(game, SnakeGame::GameState::State::DIFFICULTY_SCREEN);
    }

    void onRecords()
    {

    }

    void onSettings()
    {

    }

    void onExit()
    {

    }
}

void SnakeGame::DrawMainMenu(const Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Змейка", game.fonts, window);
    DrawMenuOption(L"Начать игру",  SelectedOption::START_GAME, 200.f, game.fonts, window);
    DrawMenuOption(L"Уровень сложности", SelectedOption::DIFFICULTY, 240.f, game.fonts, window);
    DrawMenuOption(L"Таблица рекордов", SelectedOption::RECORDS, 280.f, game.fonts, window);
    DrawMenuOption(L"Настройки", SelectedOption::SETTINGS, 320.f, game.fonts, window);
    DrawMenuOption(L"Выход", SelectedOption::EXIT, 360.f, game.fonts, window);
}

void SnakeGame::SelectNextMainMenuOption()
{
    int index = static_cast<int>(selectedOption) + 1;
    if (index > 4)
    {
        index = 0;
    }

    selectedOption = GetOptionByIndex(index);
}

void SnakeGame::SelectPrevMainMenuOption()
{
    int index = static_cast<int>(selectedOption) - 1;
    if (index < 0)
    {
        index = 4;
    }

    selectedOption = GetOptionByIndex(index);
}

void SnakeGame::HandleMainMenuSelection(Game& game)
{
    if (selectedOption == SelectedOption::START_GAME)
    {
        onStartGame(game);
    }
    else if (selectedOption == SelectedOption::DIFFICULTY)
    {
        onDifficulty(game);
    }
    else if (selectedOption == SelectedOption::RECORDS)
    {
        onRecords();
    }
    else if (selectedOption == SelectedOption::SETTINGS)
    {
        onSettings();
    }
    else if (selectedOption == SelectedOption::EXIT)
    {
        onExit();
    }
}
