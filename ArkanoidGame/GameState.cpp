#include "GameState.h"
#include "GameStateData.h"
#include "GameStatePlaying.h"
#include "GameStateGameOver.h"
#include "GameStateGameWin.h"
#include "GameStatePauseMenu.h"
#include "GameStateMainMenu.h"
#include "GameStateRecords.h"
#include <assert.h>

namespace RogaliqueGame
{
	GameState::GameState(GameStateType type, bool isExclusivelyVisible)
		:type(type), isExclusivelyVisible(isExclusivelyVisible)
	{
		switch (type)
		{
		case GameStateType::MainMenu:
		{
			data = std::make_unique<GameStateMainMenuData>();
			break;
		}

		case GameStateType::Playing:
		{
			data = std::make_unique<GameStatePlayingData>();
			break;
		}
		case GameStateType::GameOver:
		{
			data = std::make_unique<GameStateGameOverData>();
			break;
		}
		case GameStateType::GameWin:
		{
			data = std::make_unique<GameStateGameWinData>();
			break;
		}
		case GameStateType::ExitDialog:
		{
			data = std::make_unique<GameStatePauseMenuData>();
			break;
		}
		case GameStateType::Records:
		{
			data = std::make_unique<GameStateRecordsData>();
			break;
		}
		default:
		{
			assert(false);
			break;
		}
		}
		if (data) 
		{
			data->Init();
		}
	}
	GameState::~GameState()
	{
		if (data)
		{
			data = nullptr;
		}
	}
	void GameState::Update(float timeDelta)
	{
		data->Update(timeDelta);
	}
	void GameState::Draw(sf::RenderWindow& window)
	{
		data->Draw(window);
	}
	void GameState::HandelWindowEvent(sf::Event& event)
	{
		data->HandleWindowEvent(event);
	}
	
}
