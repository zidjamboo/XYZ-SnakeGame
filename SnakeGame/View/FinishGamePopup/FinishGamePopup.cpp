#include "FinishGamePopup.h"

#include "../../Game/Game.h"
#include "../Fonts/Fonts.h"
#include "../../Score/Score.h"
#include "../../Constants.h"

namespace
{
    constexpr float POPUP_X_SIZE = 300.f;
    constexpr float POPUP_Y_SIZE = 500.f;
    constexpr float BORDER_SIZE = 10.f;
    constexpr int MAX_RECORD_SIZE = 24;
    constexpr float FIX_FONT_ALIGN = 5.f;

    enum class SelectedButton
    {
        START_GAME, TO_MAIN_MENU
    };

    SelectedButton selectedButton = SelectedButton::START_GAME;

    void DrawPopupBackground(sf::RenderWindow& window)
    {
        sf::RectangleShape border;
        border.setSize({POPUP_X_SIZE, POPUP_Y_SIZE});
        sf::Vector2f whiteBackgroundPosition = {(SCREEN_WIDTH - POPUP_X_SIZE) / 2.f, (SCREEN_HEIGHT - POPUP_Y_SIZE) / 2.f};
        border.setPosition(whiteBackgroundPosition);
        border.setFillColor(sf::Color::White);

        sf::RectangleShape innerRect;
        innerRect.setSize({POPUP_X_SIZE - BORDER_SIZE * 2, POPUP_Y_SIZE - BORDER_SIZE * 2});
        innerRect.setPosition({whiteBackgroundPosition.x + BORDER_SIZE, whiteBackgroundPosition.y + BORDER_SIZE});
        innerRect.setFillColor(sf::Color::Black);

        window.draw(border);
        window.draw(innerRect);
    }

    void DrawTitleText(const SnakeGame::Fonts& fonts, sf::RenderWindow& window)
    {
        sf::Text title;
        title.setFont(fonts.robotoBold);
        title.setCharacterSize(28);
        title.setFillColor(sf::Color::White);
        title.setString(L"Количество очков");
        title.setPosition({(SCREEN_WIDTH - title.getGlobalBounds().width) / 2, 100.f});

        window.draw(title);
    }

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
        title.setPosition({(SCREEN_WIDTH - title.getGlobalBounds().width) / 2, 200.f});

        window.draw(title);
    }

    std::string repeatSpace(int size)
    {
        std::string result;
        result.reserve(size);

        for (int i = 0; i < size; ++i)
        {
            result.append(" ");
        }

        return result;
    }

    std::string createRecordString(const int& lineNumber, const unsigned int& record)
    {
        std::string result;
        result.append(std::to_string(lineNumber));
        result.append(".");

        std::string recordValueString = std::to_string(record);

        std::string spaces = repeatSpace(MAX_RECORD_SIZE - static_cast<int>(result.size() + recordValueString.size()));

        result.append(spaces);
        result.append(recordValueString);

        return result;
    }

    void DrawRecords(const SnakeGame::Fonts& fonts, std::vector<unsigned int>& records, sf::RenderWindow& window)
    {
        std::sort(records.begin(), records.end(), std::greater<>());

        float startYPosition = 230.f;
        int counter = 1;
        for (unsigned int record : records)
        {
            sf::Text text;
            text.setFont(fonts.robotoRegular);
            text.setCharacterSize(18);
            text.setFillColor(sf::Color::White);
            text.setString(createRecordString(counter, record));
            text.setPosition((SCREEN_WIDTH - text.getGlobalBounds().width) / 2, startYPosition);

            window.draw(text);

            counter++;

            if (counter > 3)
            {
                break;
            }

            startYPosition += 20.f;
        }
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
        sf::Vector2f buttonBackgroundPosition = {(SCREEN_WIDTH - buttonBackgrond.getGlobalBounds().width) / 2, 325.f};
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
        sf::Vector2f buttonBackgoundSize = {200.f, 75.f};
        buttonBackgrond.setSize(buttonBackgoundSize);
        sf::Vector2f buttonBackgroundPosition = {(SCREEN_WIDTH - buttonBackgrond.getGlobalBounds().width) / 2, 425.f};
        buttonBackgrond.setPosition(buttonBackgroundPosition);

        sf::Text buttonText;
        buttonText.setFont(fonts.robotoBold);
        buttonText.setFillColor(sf::Color::Black);
        buttonText.setCharacterSize(24);
        buttonText.setString(L"В главное меню");
        buttonText.setPosition({
            (SCREEN_WIDTH - buttonText.getGlobalBounds().width) / 2,
            buttonBackgroundPosition.y + (buttonBackgoundSize.y - buttonText.getGlobalBounds().height) / 2 - FIX_FONT_ALIGN
        });

        window.draw(buttonBackgrond);
        window.draw(buttonText);
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

void SnakeGame::DrawFinishGamePopup(const Game& game, sf::RenderWindow& window)
{
    DrawPopupBackground(window);
    DrawTitleText(game.fonts, window);
    DrawCurrentScore(game.fonts, game.score, window);
    DrawRecordTitle(game.fonts, window);
    std::vector<unsigned int> records = {100, 200, 59, 1};
    DrawRecords(game.fonts, records, window);
    DrawStartGameButton(game.fonts, window);
    DrawToMainMenuButton(game.fonts, window);
}
