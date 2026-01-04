#include "ScoreTopPanel.h"

#include "../../Constants.h"
#include "../../Game/Game.h"

void SnakeGame::DrawScoreTopPanel(const Game& game, sf::RenderWindow& window)
{
    sf::RectangleShape panel;
    panel.setPosition({0.f, 0.f});
    panel.setSize({SCREEN_WIDTH, SCORE_TOP_PANEL_HEIGHT});
    panel.setFillColor(sf::Color::Yellow);

    sf::Text scoreText;
    scoreText.setFont(game.fonts.robotoRegular);
    scoreText.setString(std::to_string(game.score.value));
    scoreText.setCharacterSize(22);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition({10.f, 0.f});

    window.draw(panel);
    window.draw(scoreText);
}
