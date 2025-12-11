#include "KeyboardHelper.h"

#include <set>

static std::set<sf::Keyboard::Key> pressedKeys;

bool SnakeGame::isKeyPressed(sf::Keyboard::Key key)
{
    if (pressedKeys.find(key) != pressedKeys.end())
    {
        return false;
    }

    bool isKeyPressed = sf::Keyboard::isKeyPressed(key);

    if (isKeyPressed)
    {
       pressedKeys.emplace(key);
    }

    return isKeyPressed;
}

void SnakeGame::HandleKeysUnpress()
{
    std::set<sf::Keyboard::Key> keysToRemove;

    for (auto& key : pressedKeys)
    {
        if (!sf::Keyboard::isKeyPressed(key))
        {
            keysToRemove.emplace(key);
        }
    }

    for (auto& key : keysToRemove)
    {
        pressedKeys.erase(key);
    }
}
