#include "Snake.h"

#include "../../Constants.h"
#include "../../Game/Game.h"

void SnakeGame::DrawSnake(Game& game, sf::RenderWindow& window)
{
    for (auto& part: game.snake)
    {
        sf::RectangleShape rect;
        rect.setSize({CELL_SIZE, CELL_SIZE});
        rect.setPosition(
            CELL_SIZE * static_cast<float>(part.position.x),
            CELL_SIZE * static_cast<float>(part.position.y));
        rect.setFillColor(sf::Color::Red);

        window.draw(rect);
    }
}
