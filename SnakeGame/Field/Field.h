#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "../Types.h"

namespace SnakeGame
{
    void InitField();
    void OccupyFieldPosition(FieldPosition fieldPosition);
    void FreeFieldPosition(FieldPosition fieldPosition);
    sf::Vector2f ToDrawPosition(FieldPosition fieldPosition);
    std::vector<FieldPosition> getFreePositions();
}
