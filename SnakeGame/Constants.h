#pragma once

// Screen resolution
constexpr unsigned int SCREEN_WIDTH = 800;
constexpr unsigned int SCREEN_HEIGHT = 600;

// field
constexpr float CELL_SIZE = 25.f;
constexpr int X_CELLS = SCREEN_WIDTH / static_cast<int>(CELL_SIZE);
constexpr int Y_CELLS = SCREEN_HEIGHT / static_cast<int>(CELL_SIZE);

constexpr unsigned int CELL_COLOR_1 = 0x008000FF;
constexpr unsigned int CELL_COLOR_2 = 0x228b22FF;
