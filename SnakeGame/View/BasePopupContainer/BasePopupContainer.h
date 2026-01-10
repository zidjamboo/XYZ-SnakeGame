#pragma once
#include <SFML/Graphics.hpp>
#include "../Fonts/Fonts.h"

namespace SnakeGame
{
    void DrawBasePopupContainer(sf::RenderWindow& window);
    void DrawBasePopupTitle(const wchar_t* str, const Fonts& fonts, sf::RenderWindow& window);
}
