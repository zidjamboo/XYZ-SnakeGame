#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    namespace GameFinishState
    {
        void onActive(Game& game);
        void onUpdate(Game& game, const float& deltaTime);
        void onDraw(Game& game, sf::RenderWindow& window);
        void onInactive();
    }
}
