#include "BackGround.h"

#include "../Constants.h"
#include "../Game/Game.h"

void SnakeGame::InitBackground(Game& game)
{
    sf::RenderTexture renderTexture;
    renderTexture.create(SCREEN_WIDTH, SCREEN_HEIGHT);

    int xMax = SCREEN_WIDTH / static_cast<int>(CELL_SIZE);
    int yMax = SCREEN_HEIGHT / static_cast<int>(CELL_SIZE);
    for (int x = 0; x < xMax; ++x)
    {
        for (int y = 0; y < yMax; ++y)
        {
            sf::Color color = (x + y) % 2 == 0 ? sf::Color(CELL_COLOR_1) : sf::Color(CELL_COLOR_2);
            sf::RectangleShape rect;
            rect.setPosition(25.f * static_cast<float>(x), 25.f * static_cast<float>(y));
            rect.setSize({25.f, 25.f});
            rect.setFillColor(color);

            renderTexture.draw(rect);
        }
    }

    game.background.texture = renderTexture.getTexture();
    game.background.sprite.setTexture(game.background.texture);
    game.background.sprite.setPosition(0.f, 0.f);
}
