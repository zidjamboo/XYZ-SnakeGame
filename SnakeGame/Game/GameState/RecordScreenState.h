#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    namespace RecordScreenState
    {
        void onActive(Game& game);
        void onUpdate(Game& game, const float& deltaTime, sf::Event& event);
        void onDraw(Game& game, sf::RenderWindow& window);
        void onInactive(Game& game);
    }
}
