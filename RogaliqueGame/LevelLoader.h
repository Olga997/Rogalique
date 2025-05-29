#pragma once
#include <vector>
#include <string>
#include <memory>
#include <map>

namespace RogaliqueGame
{
	enum class BlockType
	{
		Simple,
		TwoHit,
		Unbreackable
	};

	struct Level
	{
		
	};

	class LevelLoader final
	{
	public:
		LevelLoader()
		{
			LoadLevelsFromFile();
		}
		Level& GetLevel(int i);
		~LevelLoader() = default;
		int GetLevelCount();
	private:
		void LoadLevelsFromFile();
		std::vector<Level> levels;
	};
}