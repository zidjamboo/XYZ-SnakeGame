#include "FinishGamePopup.h"

#include "../../Game/Game.h"
#include "../Fonts/Fonts.h"
#include "../../Constants.h"
#include "../BasePopupContainer/BasePopupContainer.h"
#include "../CommonRecordsView/CommonRecordView.h"

namespace
{
    constexpr float FIX_FONT_ALIGN = 5.f;

    enum class SelectedButton
    {
        START_GAME, TO_MAIN_MENU
    };

    SelectedButton selectedButton = SelectedButton::START_GAME;

    void DrawCurrentScore(const SnakeGame::Fonts& fonts, const SnakeGame::Score& score, sf::RenderWindow& window)
    {
        sf::Text scoreText;
        scoreText.setFont(fonts.robotoBold);
        scoreText.setCharacterSize(28);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setString(std::to_string(score.value));
        scoreText.setPosition({(SCREEN_WIDTH - scoreText.getGlobalBounds().width) / 2, 150.f});

        window.draw(scoreText);
    }

    void DrawRecordTitle(const SnakeGame::Fonts& fonts, sf::RenderWindow& window)
    {
        sf::Text title;
        title.setFont(fonts.robotoRegular);
        title.setCharacterSize(18);
        title.setFillColor(sf::Color::White);
        title.setString(L"Рекорды");
        title.setPosition({(SCREEN_WIDTH - title.getGlobalBounds().width) / 2, 190.f});

        window.draw(title);
    }

    void DrawStartGameButton(const SnakeGame::Fonts& fonts, sf::RenderWindow& window)
    {

        sf::Color color;
        if (selectedButton == SelectedButton::START_GAME)
        {
            color = sf::Color::Yellow;
        } else
        {
            color = sf::Color:: White;
        }

        sf::RectangleShape buttonBackgrond;
        buttonBackgrond.setFillColor(color);
        sf::Vector2f buttonBackgoundSize = {200.f, 75.f};
        buttonBackgrond.setSize(buttonBackgoundSize);
        sf::Vector2f buttonBackgroundPosition = {(SCREEN_WIDTH - buttonBackgrond.getGlobalBounds().width) / 2, 350.f};
        buttonBackgrond.setPosition(buttonBackgroundPosition);

        sf::Text buttonText;
        buttonText.setFont(fonts.robotoBold);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setCharacterSize(24);
        buttonText.setString(L"Начать игру");
        buttonText.setPosition({
            (SCREEN_WIDTH - buttonText.getGlobalBounds().width) / 2,
            buttonBackgroundPosition.y + (buttonBackgoundSize.y - buttonText.getGlobalBounds().height) / 2 - FIX_FONT_ALIGN
        });

        window.draw(buttonBackgrond);
        window.draw(buttonText);
    }

    void OnStartGameButtonClick(SnakeGame::Game& game)
    {
        ClearGameStateStack(game);
        SnakeGame::PushGameState(game, SnakeGame::GameState::State::PLAYING);
    }

    void DrawToMainMenuButton(const SnakeGame::Fonts& fonts, sf::RenderWindow& window)
    {
        sf::Color color;
        if (selectedButton == SelectedButton::TO_MAIN_MENU)
        {
            color = sf::Color::Yellow;
        } else
        {
            color = sf::Color:: White;
        }

        sf::RectangleShape buttonBackgrond;
        buttonBackgrond.setFillColor(color);
        sf::Vector2f buttonBackgroundSize = {200.f, 75.f};
        buttonBackgrond.setSize(buttonBackgroundSize);
        sf::Vector2f buttonBackgroundPosition = {(SCREEN_WIDTH - buttonBackgrond.getGlobalBounds().width) / 2, 440.f};
        buttonBackgrond.setPosition(buttonBackgroundPosition);

        sf::Text buttonText;
        buttonText.setFont(fonts.robotoBold);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setCharacterSize(24);
        buttonText.setString(L"В главное меню");
        buttonText.setPosition({
            (SCREEN_WIDTH - buttonText.getGlobalBounds().width) / 2,
            buttonBackgroundPosition.y + (buttonBackgroundSize.y - buttonText.getGlobalBounds().height) / 2 - FIX_FONT_ALIGN
        });

        window.draw(buttonBackgrond);
        window.draw(buttonText);
    }

    void OnToMainMenuButtonClick(SnakeGame::Game& game)
    {
        ClearGameStateStack(game);
        SnakeGame::PushGameState(game, SnakeGame::GameState::State::MAIN_MENU);
    }
}

void SnakeGame::SwitchSelectedFinishGameButton()
{
    if (selectedButton == SelectedButton::START_GAME)
    {
        selectedButton = SelectedButton::TO_MAIN_MENU;
    }
    else
    {
        selectedButton = SelectedButton::START_GAME;
    }
}

void SnakeGame::HandleSelectedFinishGameButtonClick(SnakeGame::Game& game)
{
    if (selectedButton == SelectedButton::START_GAME)
    {
        OnStartGameButtonClick(game);
    }
    else if (selectedButton == SelectedButton::TO_MAIN_MENU)
    {
        OnToMainMenuButtonClick(game);
    }
}

void SnakeGame::DrawFinishGamePopup(Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Количество очков", game.fonts, window);
    DrawCurrentScore(game.fonts, game.currentScore, window);
    DrawRecordTitle(game.fonts, window);
    DrawRecords(game.fonts, game.savedScores, 5, 230.f, window);
    DrawStartGameButton(game.fonts, window);
    DrawToMainMenuButton(game.fonts, window);
}
