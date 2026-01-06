#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "SFML/Window/Event.hpp"

namespace SnakeGame
{
    bool isKeyPressed(sf::Keyboard::Key key);
    void HandleKeysUnpress();
    bool isApplyTextEnteredUnicode(const sf::Uint32& unicode);
    void HandleTextEnteredEventsDelay(const float& deltaTime);
}
