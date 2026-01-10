#include "MainMenuView.h"

#include "../../Game/Game.h"
#include "../BasePopupContainer/BasePopupContainer.h"

void SnakeGame::DrawMainMenu(const Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Змейка", game.fonts, window);
}
