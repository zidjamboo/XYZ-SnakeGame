#pragma once
#include <SFML/Graphics/Texture.hpp>

namespace SnakeGame
{
    struct AppleTextures
    {
        sf::Texture appleTexture;
    };

    struct SnakeTextures
    {
        sf::Texture headUp;
        sf::Texture headDown;
        sf::Texture headLeft;
        sf::Texture headRight;

        sf::Texture bodyVertical;
        sf::Texture bodyHorizontal;
        sf::Texture bodyBottomLeft;
        sf::Texture bodyBottomRight;
        sf::Texture bodyTopLeft;
        sf::Texture bodyTopRight;

        sf::Texture tailUp;
        sf::Texture tailDown;
        sf::Texture tailLeft;
        sf::Texture tailRight;
    };
    struct Textures
    {
        AppleTextures appleTextures;
        SnakeTextures snakeTextures;
    };

    struct Game;
    void InitTextureResources(Game& game);
}
