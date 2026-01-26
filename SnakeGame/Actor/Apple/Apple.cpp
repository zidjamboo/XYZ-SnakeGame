#include "Apple.h"
#include "../../Constants.h"
#include "../../Field/Field.h"
#include "../../Game/Game.h"
#include "../../Utils/Math.h"
#include "../../Utils/SpriteUtils.h"

void SnakeGame::InitApple(Apple& apple)
{
}

void SnakeGame::ReplaceApple(Apple& apple)
{
    std::vector<FieldPosition> freePositions = getFreePositions();

    if (std::empty(freePositions))
    {
        apple.position = {-1, -1};
        return;
    }

    apple.position = freePositions[GetRandomInt(0, static_cast<int>(freePositions.size()) - 1)];
}

void SnakeGame::DrawApple(const Game& game, sf::RenderWindow& window)
{
    sf::Sprite appleSprite;
    appleSprite.setTexture(game.textures.appleTextures.appleTexture);
    appleSprite.setScale(GetSpriteScale(
        appleSprite, {static_cast<float>(CELL_SIZE), static_cast<float>(CELL_SIZE)}));
    appleSprite.setPosition(ToDrawPosition(game.apple.position));

    window.draw(appleSprite);
}
