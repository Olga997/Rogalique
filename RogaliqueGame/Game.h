#pragma once
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "GameSettings.h"
#include "GameState.h"
#include <unordered_map>

namespace RogaliqueGame
{
	enum class GameOptions: std::uint8_t
	{
		InfiniteApples = 1 << 0,
		WithAcceleration = 1 << 1,

		Default = InfiniteApples | WithAcceleration,
		Empty = 0
	};

	enum class GameStateChangeType
	{
		None,
		Push,
		Pop,
		Switch
	};

	class Game
	{
	public:
		void StartGame();
		void PauseGame();
		void WinGame();
		void LooseGame();
		void UpdateGame(float timeDelta, sf::RenderWindow& window);
		void ExitGame();
		void QuitGame();
		void ShowRecords();
		void LoadNextLevel();

		using RecordsTable = std::unordered_map<std::string, int>;

		Game();
		~Game();


		bool IsEnableOptions(GameOptions option) const;
		void SetOption(GameOptions option, bool value);

		const RecordsTable& GetRecordsTable() const { return recordsTable; }
		int GetRecordByPlayerId(const std::string& playerId) const;

		void PopState();

	private:
		void HandleWindowEvents(sf::RenderWindow& window);
		bool Update(float timeDelta); // Return false if game should be closed
		void Draw(sf::RenderWindow& window);
		void Shutdown();

		void UpdateRecord(const std::string& playerId, int score);

		void PushState(GameStateType newState, bool isExclusivelyVisible);
		void SwitchStateTo(GameStateType newState);

		
	private:
		std::vector<GameState> stateStack;
		GameStateChangeType stateChangeType = GameStateChangeType::None;
		GameStateType pendingGameStateType = GameStateType::None;
		bool pendingGameStateIsExclusivelyVisible = false;

		GameOptions options = GameOptions::Default;
		RecordsTable recordsTable;
	};
}
