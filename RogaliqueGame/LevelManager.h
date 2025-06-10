#pragma once
#include "DeveloperLevel.h"

namespace RogaliqueGame {
class LevelManager {
   public:
    LevelManager() = default;
    ~LevelManager() = default;
    
      static LevelManager& Instance() {
        static LevelManager instance;
        return instance;
    }
    void AddLevel(std::shared_ptr<DeveloperLevel> level);
    void StartFirstLevel();
    void LoadNextLevel();
    void RestartCurrentLevel();
    std::shared_ptr<DeveloperLevel> GetCurrentLevel();

   private:
    std::vector<std::shared_ptr<DeveloperLevel>> levels;
    size_t currentLevelIndex = 0;
};
}  // namespace RogaliqueGame
