#include "CommonRecordView.h"
#include "../../Constants.h"

namespace
{
    constexpr float RECORD_ROW_WIDTH = 150.f;

    void DrawRecordRow(
       const SnakeGame::ScoreRow& scoreRow,
       const float& yPosition,
       const SnakeGame::Fonts& fonts,
       sf::RenderWindow& window)
    {
        float recordStartXPosition = (SCREEN_WIDTH - RECORD_ROW_WIDTH) / 2;

        sf::Text userNameText;
        userNameText.setFont(fonts.robotoRegular);
        userNameText.setCharacterSize(16);
        userNameText.setFillColor(sf::Color::White);
        userNameText.setString(scoreRow.userName);
        userNameText.setPosition({recordStartXPosition, yPosition});

        sf::Text scoreText;
        scoreText.setFont(fonts.robotoRegular);
        scoreText.setCharacterSize(16);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setString(std::to_string(scoreRow.score.value));
        scoreText.setPosition({recordStartXPosition + RECORD_ROW_WIDTH - scoreText.getGlobalBounds().width, yPosition});

        window.draw(userNameText);
        window.draw(scoreText);
    }
}

void SnakeGame::DrawRecords(
    const Fonts& fonts,
    ScoreTable& scoreTable,
    const int& maxRows,
    const float& startYPosition,
    sf::RenderWindow& window
)
{
    std::sort(scoreTable.rows.begin(), scoreTable.rows.end(), std::greater<>());

    float yPosition = startYPosition;
    int counter = 0;
    for (const ScoreRow& row : scoreTable.rows)
    {
        DrawRecordRow(row, yPosition, fonts, window);

        if (++counter > maxRows - 1)
        {
            break;
        }

        yPosition += 20.f;
    }
}
