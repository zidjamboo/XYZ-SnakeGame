#pragma once

#include <functional>

#include "Snake.h"

namespace SnakeGame
{
    void ChangeDirection(Snake& snake);
    void DoSnakeAction(Game& game, const std::function<void()>& onAppleEat);
}
