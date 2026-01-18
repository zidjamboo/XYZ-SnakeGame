#include "RecordScreenVIew.h"
#include "../../View/BasePopupContainer/BasePopupContainer.h"
#include "../../Game/Game.h"
#include "../CommonRecordsView/CommonRecordView.h"

void SnakeGame::DrawRecordScreenView(Game& game, sf::RenderWindow& window)
{
    DrawBasePopupContainer(window);
    DrawBasePopupTitle(L"Таблица рекордов", game.fonts, window);
    DrawRecords(game.fonts, game.savedScores, 10, 150.f, window);
}
