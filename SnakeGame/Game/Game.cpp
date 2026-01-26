#include "Game.h"

#include "../Field/Field.h"
#include "../View/ScoreTopPanel/ScoreTopPanel.h"

namespace SnakeGame
{
    void InitGame(Game& game)
    {
        game.stateStack.emplace(GameState::State::MAIN_MENU);

        InitBackground(game);
        InitFonts(game);
        InitSoundResources(game);
        InitTextureResources(game);
    }

    void RestartGame(Game& game)
    {
        InitField();
        InitSnake(game.snake);
        InitApple(game.apple);
        ReplaceApple(game.apple);
    }

    void UpdateGame(Game& game, const float& deltaTime, sf::Event& event)
    {
        TopGameState(game).onUpdate(game, deltaTime, event);
        sf::SoundSource::Status status = game.soundResources.background.getStatus();
        if (game.soundSettings.isMusicEnabled && status == sf::SoundSource::Status::Stopped)
        {
            game.soundResources.background.play();
        }
        else if (!game.soundSettings.isMusicEnabled && status == sf::SoundSource::Status::Playing)
        {
            game.soundResources.background.stop();
        }
    }

    void DrawGame(Game& game, sf::RenderWindow& window)
    {
        window.clear();
        TopGameState(game).onDraw(game, window);
        window.display();
    }
}
