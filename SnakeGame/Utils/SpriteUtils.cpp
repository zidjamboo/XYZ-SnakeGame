#include "SpriteUtils.h"

sf::Vector2f SnakeGame::GetSpriteScale(sf::Sprite& sprite, sf::Vector2f size)
{
    auto bounds = sprite.getGlobalBounds();
    return {size.x / bounds.width, size.y / bounds.height};
}
