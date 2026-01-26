#include "Snake.h"

#include "../../Constants.h"
#include "../../Field/Field.h"
#include "../../Game/Game.h"
#include "../../Utils/SpriteUtils.h"

namespace
{
    SnakeGame::Direction GetPartRelativeDirection(const SnakeGame::SnakePart& current, const SnakeGame::SnakePart& other)
    {
        if (current.position.y > other.position.y)
        {
            return SnakeGame::Direction::UP;
        }

        if (current.position.y < other.position.y)
        {
            return SnakeGame::Direction::DOWN;
        }

        if (current.position.x < other.position.x)
        {
            return SnakeGame::Direction::RIGHT;
        }

        if (current.position.x > other.position.x)
        {
            return SnakeGame::Direction::LEFT;
        }

        return SnakeGame::Direction::NONE;
    }

    const sf::Texture* GetPartTexture(
        const SnakeGame::Game& game,
        const SnakeGame::SnakePart& current,
        const SnakeGame::SnakePart* prevPart,
        const SnakeGame::SnakePart* nextPart
        )
    {
        
        // head
        if (prevPart == nullptr)
        {
            const SnakeGame::Direction& snakeDirection = game.snake.direction;

            if (snakeDirection == SnakeGame::Direction::UP)
            {
                return &game.textures.snakeTextures.headUp;
            }

            if (snakeDirection == SnakeGame::Direction::DOWN)
            {
                return &game.textures.snakeTextures.headDown;
            }

            if (snakeDirection == SnakeGame::Direction::LEFT)
            {
                return &game.textures.snakeTextures.headLeft;
            }

            if (snakeDirection == SnakeGame::Direction::RIGHT)
            {
                return &game.textures.snakeTextures.headRight;
            }
        }
        // tail
        else if (nextPart == nullptr)
        {
            SnakeGame::Direction prevPartDirection = GetPartRelativeDirection(current, *prevPart);

            if (prevPartDirection == SnakeGame::Direction::UP)
            {
                return &game.textures.snakeTextures.tailDown;
            }

            if (prevPartDirection == SnakeGame::Direction::DOWN)
            {
                return &game.textures.snakeTextures.tailUp;
            }

            if (prevPartDirection == SnakeGame::Direction::LEFT)
            {
                return &game.textures.snakeTextures.tailRight;
            }

            if (prevPartDirection == SnakeGame::Direction::RIGHT)
            {
                return &game.textures.snakeTextures.tailLeft;
            }
        }
        // body
        else
        {
            SnakeGame::Direction prevPartDirection = GetPartRelativeDirection(current, *prevPart);
            SnakeGame::Direction nextPartDirection = GetPartRelativeDirection(current, *nextPart);

            if (prevPartDirection == SnakeGame::Direction::UP && nextPartDirection == SnakeGame::Direction::DOWN ||
            prevPartDirection == SnakeGame::Direction::DOWN && nextPartDirection == SnakeGame::Direction::UP)
                {

                return &game.textures.snakeTextures.bodyVertical;
            }


            if (prevPartDirection == SnakeGame::Direction::LEFT && nextPartDirection == SnakeGame::Direction::RIGHT ||
                prevPartDirection == SnakeGame::Direction::RIGHT && nextPartDirection == SnakeGame::Direction::LEFT)
            {
                return &game.textures.snakeTextures.bodyHorizontal;
            }

            if (prevPartDirection == SnakeGame::Direction::UP && nextPartDirection == SnakeGame::Direction::LEFT ||
                prevPartDirection == SnakeGame::Direction::LEFT && nextPartDirection == SnakeGame::Direction::UP)
            {
                return &game.textures.snakeTextures.bodyTopLeft;
            }

            if (prevPartDirection == SnakeGame::Direction::UP && nextPartDirection == SnakeGame::Direction::RIGHT ||
                prevPartDirection == SnakeGame::Direction::RIGHT && nextPartDirection == SnakeGame::Direction::UP)
            {
                return &game.textures.snakeTextures.bodyTopRight;
            }

            if (prevPartDirection == SnakeGame::Direction::DOWN && nextPartDirection == SnakeGame::Direction::LEFT ||
                prevPartDirection == SnakeGame::Direction::LEFT && nextPartDirection == SnakeGame::Direction::DOWN)
            {
                return &game.textures.snakeTextures.bodyBottomLeft;
            }

            if (prevPartDirection == SnakeGame::Direction::DOWN && nextPartDirection == SnakeGame::Direction::RIGHT ||
                prevPartDirection == SnakeGame::Direction::RIGHT && nextPartDirection == SnakeGame::Direction::DOWN)
            {
                return &game.textures.snakeTextures.bodyBottomRight;
            }
        }

        return nullptr;
    }

    std::pair<const SnakeGame::SnakePart*, const SnakeGame::SnakePart*> GetNeighbors(
        const std::list<SnakeGame::SnakePart>& list,
        const std::list<SnakeGame::SnakePart>::const_iterator& current
    )
    {
        const SnakeGame::SnakePart* prev = nullptr;
        const SnakeGame::SnakePart* next = nullptr;

        if (current != list.begin())
        {
            auto prevIterator = current;
            --prevIterator;
            prev = &*prevIterator;
        }

        auto nextIterator = current;
        ++nextIterator;
        if (nextIterator != list.end())
        {
            next = &*nextIterator;
        }



        return {prev, next};
    }
}

void SnakeGame::InitSnake(Snake& snake)
{
    snake.parts.clear();
    SnakePart head;
    head.position.x = 16;
    head.position.y = 12;
    snake.parts.emplace_front(head);
}

void SnakeGame::DrawSnake(const Game& game, sf::RenderWindow& window)
{
    const std::list<SnakePart>& snakeParts = game.snake.parts;
    for (auto it = snakeParts.begin(); it != snakeParts.end(); ++it)
    {
        auto neighbors = GetNeighbors(snakeParts, it);
        const sf::Texture& texture = *GetPartTexture(game, *it, neighbors.first, neighbors.second);

        sf::Sprite snakeSprite;
        snakeSprite.setTexture(texture);
        snakeSprite.setScale(GetSpriteScale(snakeSprite, {CELL_SIZE, CELL_SIZE}));
        snakeSprite.setPosition(ToDrawPosition(it->position));

        window.draw(snakeSprite);
    }
}

bool SnakeGame::isSnakeSelfCollide(Snake& snake)
{
    for (auto it = ++snake.parts.begin(); it != snake.parts.end(); ++it)
    {
        if (it->position == snake.head().position)
        {
            return true;
        }
    }

    return false;
}
