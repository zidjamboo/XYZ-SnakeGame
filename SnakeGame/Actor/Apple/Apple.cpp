#include "Apple.h"
#include "../../Constants.h"
#include "../../Field/Field.h"
#include "../../Game/Game.h"
#include "../../Utils/Math.h"

void SnakeGame::InitApple(Apple& apple)
{

}

void SnakeGame::ReplaceApple(Apple& apple)
{
    std::vector<FieldPosition> freePositions = getFreePositions();
    apple.position = freePositions[GetRandomInt(0, static_cast<int>(freePositions.size()) - 1)];
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
