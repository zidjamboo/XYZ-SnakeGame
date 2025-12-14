#pragma once

#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    namespace PlayingState
    {
        void onActive();
        void onUpdate(Game& game, const float& deltaTime);
        void onDraw(Game& game, sf::RenderWindow& window);
        void onInactive();
    }
}
