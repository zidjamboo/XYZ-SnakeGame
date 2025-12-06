#pragma once
#include <SFML/Graphics.hpp>

namespace SnakeGame
{
    struct Game;
    namespace MainMenuState
    {
        void onActive();
        void onUpdate(Game& game);
        void onDraw(Game& game, sf::RenderWindow& window);
        void onInactive();
    }
}
