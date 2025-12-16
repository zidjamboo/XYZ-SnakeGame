#include "ScoreTopPanel.h"

#include <cassert>

#include "../../Constants.h"
#include "../../Score/Score.h"

namespace
{
    sf::Font robotoRegular;
}

void SnakeGame::InitScoreTopPanel()
{
    assert(robotoRegular.loadFromFile("Resources\\Fonts\\Roboto-Regular.ttf"));
}

void SnakeGame::DrawScoreTopPanel(const Score& score, sf::RenderWindow& window)
{
    sf::RectangleShape panel;
    panel.setPosition({0.f, 0.f});
    panel.setSize({SCREEN_WIDTH, SCORE_TOP_PANEL_HEIGHT});
    panel.setFillColor(sf::Color::Yellow);

    sf::Text scoreText;
    scoreText.setFont(robotoRegular);
    scoreText.setString(std::to_string(score.value));
    scoreText.setCharacterSize(22);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition({10.f, 0.f});

    window.draw(panel);
    window.draw(scoreText);
}
