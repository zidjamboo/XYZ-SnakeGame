#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Vector2.hpp"

namespace SnakeGame
{
    sf::Vector2f GetSpriteScale(sf::Sprite& sprite, sf::Vector2f size);
}
