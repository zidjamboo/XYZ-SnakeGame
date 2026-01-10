#include "BasePopupContainer.h"
#include <../../Constants.h>

namespace
{
    constexpr float POPUP_X_SIZE = 300.f;
    constexpr float POPUP_Y_SIZE = 500.f;
    constexpr float BORDER_SIZE = 10.f;
}

void SnakeGame::DrawBasePopupContainer(sf::RenderWindow& window)
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

void SnakeGame::DrawBasePopupTitle(const wchar_t* str, const Fonts& fonts, sf::RenderWindow& window)
{
    sf::Text title;
    title.setFont(fonts.robotoBold);
    title.setCharacterSize(28);
    title.setFillColor(sf::Color::White);
    title.setString(str);
    title.setPosition({(SCREEN_WIDTH - title.getGlobalBounds().width) / 2, 100.f});

    window.draw(title);
}
