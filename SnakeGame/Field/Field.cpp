#include "Field.h"

#include <set>
#include "../Constants.h"

namespace
{
    std::vector<FieldPosition> freePositionsVector;

    bool isPositionInBound(FieldPosition fieldPosition)
    {
        return fieldPosition.x >= 0 && fieldPosition.x < X_CELLS &&
            fieldPosition.y >= 0 && fieldPosition.y < Y_CELLS;
    }
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
    if (!isPositionInBound(fieldPosition))
    {
        return;
    }

    auto it = std::find(
        freePositionsVector.begin(), freePositionsVector.end(), fieldPosition);

    std::swap(*it, *(freePositionsVector.end() -1));
    freePositionsVector.pop_back();
}

void SnakeGame::FreeFieldPosition(FieldPosition fieldPosition)
{
    freePositionsVector.emplace_back(fieldPosition);
}

sf::Vector2f SnakeGame::ToDrawPosition(FieldPosition fieldPosition)
{
    return {
        CELL_SIZE * static_cast<float>(fieldPosition.x),
        SCORE_TOP_PANEL_HEIGHT + CELL_SIZE * static_cast<float>(fieldPosition.y)
    };
}


std::vector<FieldPosition> SnakeGame::getFreePositions()
{
    return {freePositionsVector.begin(), freePositionsVector.end()};
}
