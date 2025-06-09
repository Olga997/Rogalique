#pragma once
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace RogaliqueGame {
enum class BlockType { Simple, TwoHit, Unbreackable };

struct Level {};

class LevelLoader final {
   public:
    LevelLoader() { LoadLevelsFromFile(); }
    Level& GetLevel(int i);
    ~LevelLoader() = default;
    int GetLevelCount();

   private:
    void LoadLevelsFromFile();
    std::vector<Level> levels;
};
}  // namespace RogaliqueGame