#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "GameStateData.h"
#include "LevelLoader.h"
#include "IObserver.h"
#include <unordered_map>

namespace RogaliqueGame
{
	class Game;
	class Block;
	class BlockFactory;

	enum class BonusType
	{
		BiggerPlatform,
		SlowBall,
		Count
	};

	class GameStatePlayingData : public GameStateData, public IObserver, public std::enable_shared_from_this<GameStatePlayingData>
	{
	public:
		void Init() override;
		void HandleWindowEvent(const sf::Event& event) override;
		void Update(float timeDelta) override;
		void Draw(sf::RenderWindow& window) override;
		void LoadNextLevel();
		void Notify(std::shared_ptr<IObservable> observable) override;
	

	private:
	
		// Resources
		sf::Font font;
		sf::SoundBuffer gameOverSoundBuffer;

		// UI data
		sf::Text inputHintText;
		sf::RectangleShape background;
		int currentScore = 0;

		// Sounds
		sf::Sound gameOverSound;
		sf::Sound bonusSound;

		//Levels
		LevelLoader levelLoder;
		int currentLevel = 0;

	};
}