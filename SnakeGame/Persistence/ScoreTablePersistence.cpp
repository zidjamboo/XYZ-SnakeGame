#include "ScoreTablePersistence.h"

#include <codecvt>
#include <fstream>
#include <string>
#include <windows.h>

namespace
{
    std::string SAVE_FOLDER = "Saves";
    std::string SCORE_TABLE_FILE = SAVE_FOLDER + "\\record_table.txt";
}

void SnakeGame::SaveScoreTable(const ScoreTable& scoreTable)
{
    DWORD attr = GetFileAttributesA(SAVE_FOLDER.c_str());
    if (!(attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY)))
    {
        CreateDirectory(std::wstring(SAVE_FOLDER.begin(), SAVE_FOLDER.end()).c_str(), NULL);
    }

    std::ofstream file(SCORE_TABLE_FILE);
    if (file.is_open())
    {
        for (const auto& row : scoreTable.rows)
        {
            file << row.userName.toAnsiString() << " " << row.score.value << std::endl;
        }
        file.close();
    }
}

void SnakeGame::LoadScoreTable(ScoreTable& scoreTable)
{
    std::ifstream file(SCORE_TABLE_FILE);
    if (file.is_open())
    {
        std::string name;
        int scoreValue;
        while (file >> name >> scoreValue)
        {
            ScoreRow row;
            row.userName = name;
            row.score.value = scoreValue;
            scoreTable.rows.push_back(row);
        }
        file.close();
    }
}
