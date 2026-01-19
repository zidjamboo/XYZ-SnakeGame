#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace SnakeGame
{
    struct SoundResources
    {
        sf::SoundBuffer loseBuffer;
        sf::Sound lose;

        sf::SoundBuffer hitBuffer;
        sf::Sound hit;

        sf::SoundBuffer menuHoverBuffer;
        sf::Sound menuHover;

        sf::Music background;
    };

    struct Game;
    void InitSoundResources(Game& game);
}
