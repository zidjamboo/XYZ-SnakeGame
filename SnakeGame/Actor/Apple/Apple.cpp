#include "Apple.h"
#include "../../Constants.h"
#include "../../Game/Game.h"
#include "../../Utils/Math.h"

void SnakeGame::InitApple(Apple& apple)
{

}

void SnakeGame::ReplaceApple(Game& game)
{
    Apple& apple = game.apple;
    apple.position.x = GetRandomInt(0, X_CELLS);
    apple.position.y = GetRandomInt(0, Y_CELLS);
}

void SnakeGame::DrawApple(const Apple& apple, sf::RenderWindow& window)
{
    sf::RectangleShape rect;
    rect.setPosition({
        CELL_SIZE * static_cast<float>(apple.position.x),
        CELL_SIZE * static_cast<float>(apple.position.y)});
    rect.setSize({CELL_SIZE, CELL_SIZE});
    rect.setFillColor(sf::Color::Green);

    window.draw(rect);
}
