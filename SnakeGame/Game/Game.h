#pragma once
#include <SFML/Graphics.hpp>

struct Game
{

};

void InitGame(Game& game);
void UpdateGame(Game& game);
void DrawGame(Game& game, sf::RenderWindow& window);
