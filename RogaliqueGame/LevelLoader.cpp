#include "LevelLoader.h"
#include "GameSettings.h"
#include <fstream>
#include <assert.h>
#include <filesystem>

namespace RogaliqueGame {
	Level& LevelLoader::GetLevel(int i) 
	{
		return levels.at(i);
	}

	void LevelLoader::LoadLevelsFromFile() {
		std::string filepath = SETTINGS.LEVELS_CONFIG_PATH;
		std::string line;
		std::ifstream file(filepath);
		int y = 0;
		
		file.close();
	}

	int LevelLoader::GetLevelCount()
	{
		return levels.size();
	}
}