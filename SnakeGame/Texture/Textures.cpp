#include <cassert>
#include "Textures.h"
#include "../Game/Game.h"

namespace
{
    std::string APPLE_RESOURCES = "Resources\\Apple\\";
    std::string SNAKE_RESOURCES = "Resources\\Snake\\";
}

void SnakeGame::InitTextureResources(Game& game)
{
    assert(game.textures.appleTextures.appleTexture.loadFromFile(APPLE_RESOURCES + "apple.png"));

    assert(game.textures.snakeTextures.headUp.loadFromFile(SNAKE_RESOURCES + "head_up.png"));
    assert(game.textures.snakeTextures.headDown.loadFromFile(SNAKE_RESOURCES + "head_down.png"));
    assert(game.textures.snakeTextures.headLeft.loadFromFile(SNAKE_RESOURCES + "head_left.png"));
    assert(game.textures.snakeTextures.headRight.loadFromFile(SNAKE_RESOURCES + "head_right.png"));

    assert(game.textures.snakeTextures.bodyBottomLeft.loadFromFile(SNAKE_RESOURCES + "body_bottomleft.png"));
    assert(game.textures.snakeTextures.bodyBottomRight.loadFromFile(SNAKE_RESOURCES + "body_bottomright.png"));
    assert(game.textures.snakeTextures.bodyTopLeft.loadFromFile(SNAKE_RESOURCES + "body_topleft.png"));
    assert(game.textures.snakeTextures.bodyTopRight.loadFromFile(SNAKE_RESOURCES + "body_topright.png"));

    assert(game.textures.snakeTextures.tailUp.loadFromFile(SNAKE_RESOURCES + "body_topright.png"));
    assert(game.textures.snakeTextures.tailDown.loadFromFile(SNAKE_RESOURCES + "body_topright.png"));
    assert(game.textures.snakeTextures.tailLeft.loadFromFile(SNAKE_RESOURCES + "body_topright.png"));
    assert(game.textures.snakeTextures.tailRight.loadFromFile(SNAKE_RESOURCES + "body_topright.png"));

}
