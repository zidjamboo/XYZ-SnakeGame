// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include <SFML/Graphics.hpp>

#include "Game/Game.h"
#include "Constants.h"
#include "Utils/KeyboardHelper.h"

const std::string RESOURCES_PATH = "Resources/";

int main()
{
	using namespace SnakeGame;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SnakeGame");

	Game game;

	InitGame(game);
	RestartGame(game);

	while (window.isOpen())
	{
		sf::sleep(sf::milliseconds(16));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		HandleKeysUnpress();
		UpdateGame(game);
		DrawGame(game, window);
	}

	return 0;
}
