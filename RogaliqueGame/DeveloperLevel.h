#pragma once
#include <iostream>
#include <array>
#include "Scene.h"
#include "Music.h"
#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "AI.h"

using namespace XYZEngine;

namespace RogaliqueGame
{
	class DeveloperLevel : public Scene
	{
	public:
		void Start() override;
		void Restart() override;
		void Stop() override;

		std::vector<std::unique_ptr<Wall>> walls;
		std::vector<std::unique_ptr<Floor>> floors;

	private:
		std::shared_ptr<Player> player;
		std::shared_ptr<AI> ai;
		std::unique_ptr<Music> music;

	
	};
}
