#include "Field.h"

#include <set>
#include "../Constants.h"

namespace
{
    std::vector<FieldPosition> freePositionsVector;
}

void SnakeGame::InitField()
{
    freePositionsVector.clear();

    for (int x = 0; x < X_CELLS; ++x)
    {
        for (int y = 0; y < Y_CELLS; ++y)
        {
            freePositionsVector.emplace_back(x, y);
        }
    }
}

void SnakeGame::OccupyFieldPosition(FieldPosition fieldPosition)
{
    auto it = std::find(
        freePositionsVector.begin(), freePositionsVector.end(), fieldPosition);

    std::swap(*it, *(freePositionsVector.end() -1));
    freePositionsVector.pop_back();
}

void SnakeGame::FreeFieldPosition(FieldPosition fieldPosition)
{
    freePositionsVector.emplace_back(fieldPosition);
}

std::vector<FieldPosition> SnakeGame::getFreePositions()
{
    return {freePositionsVector.begin(), freePositionsVector.end()};
}
