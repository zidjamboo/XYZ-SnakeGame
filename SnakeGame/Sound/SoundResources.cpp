#include <cassert>
#include "SoundResources.h"

#include "../Game/Game.h"

void SnakeGame::InitSoundResources(Game& game)
{
    assert(game.soundResources.loseBuffer.loadFromFile("Resources\\Sounds\\Maodin204__Lose.wav"));
    game.soundResources.lose.setBuffer(game.soundResources.loseBuffer);

    assert(game.soundResources.hitBuffer.loadFromFile("Resources\\Sounds\\Owlstorm__Snake_hit.wav"));
    game.soundResources.hit.setBuffer(game.soundResources.hitBuffer);

    assert(game.soundResources.menuHoverBuffer.loadFromFile("Resources\\Sounds\\Theevilsocks__menu-hover.wav"));
    game.soundResources.menuHover.setBuffer(game.soundResources.menuHoverBuffer);

    assert(game.soundResources.background.openFromFile("Resources\\Sounds\\Clinthammer__Background_Music.wav"));
    game.soundResources.background.setLoop(true);
}

void SnakeGame::PlaySound(Game& game, sf::Sound& sound)
{
    if (game.soundSettings.isSoundEnabled)
    {
        sound.play();
    }
}
