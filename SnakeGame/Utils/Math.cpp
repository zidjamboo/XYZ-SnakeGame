#include "Math.h"

#include <cstdlib>

int SnakeGame::GetRandomInt(int min, int max)
{
    return min + rand() % (max - min + 1);
}
