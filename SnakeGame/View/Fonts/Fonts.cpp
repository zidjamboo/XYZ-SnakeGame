#include "Fonts.h"

#include <cassert>

#include "../../Game/Game.h"

void SnakeGame::InitFonts(Game& game)
{
    assert(game.fonts.robotoRegular.loadFromFile("Resources\\Fonts\\Roboto-Regular.ttf"));
    assert(game.fonts.robotoBold.loadFromFile("Resources\\Fonts\\Roboto-Bold.ttf"));
}
