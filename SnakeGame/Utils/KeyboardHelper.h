#pragma once

#include <SFML/Window/Keyboard.hpp>

namespace SnakeGame
{
    bool isKeyPressed(sf::Keyboard::Key key);
    void HandleKeysUnpress();
}
