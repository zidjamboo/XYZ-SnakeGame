#pragma once
#include <vector>

#include "../Types.h"

namespace SnakeGame
{
    void InitField();
    void OccupyFieldPosition(FieldPosition fieldPosition);
    void FreeFieldPosition(FieldPosition fieldPosition);
    std::vector<FieldPosition> getFreePositions();
}
