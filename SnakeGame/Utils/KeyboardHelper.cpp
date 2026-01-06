#include "KeyboardHelper.h"

#include <set>
#include <unordered_map>

namespace
{
    std::set<sf::Keyboard::Key> pressedKeys;
    std::unordered_map<sf::Uint32, float> textEnteredMap;
}

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

bool SnakeGame::isApplyTextEnteredUnicode(const sf::Uint32& unicode)
{
    if (textEnteredMap.find(unicode) != textEnteredMap.end())
    {
        return false;
    }

    textEnteredMap.emplace(unicode, 0.15f);

    return true;
}

void SnakeGame::HandleTextEnteredEventsDelay(const float& deltaTime)
{
    std::set<sf::Uint32> toRemove;
    for (auto& pair : textEnteredMap)
    {
        pair.second = pair.second - deltaTime;

        if (pair.second <= 0)
        {
            toRemove.emplace(pair.first);
        }
    }

    for (const auto& key : toRemove)
    {
        textEnteredMap.erase(key);
    }
}
