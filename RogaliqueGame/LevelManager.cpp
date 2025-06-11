#include "LevelManager.h"

namespace RogaliqueGame {

void LevelManager::AddLevel(std::shared_ptr<DeveloperLevel> level) {
    levels.push_back(level);
}
void LevelManager::StartFirstLevel() {
    if (!levels.empty()) {
        currentLevelIndex = 0;
        levels[currentLevelIndex]->Start();
    }
}
void LevelManager::LoadNextLevel() {
    if (levels.empty()) return;

    if (currentLevelIndex + 1 >= levels.size()) {
        levels[currentLevelIndex]->Stop();
        return;
    }

    levels[currentLevelIndex]->Stop();
    currentLevelIndex++;
    levels[currentLevelIndex]->Start();
}
void LevelManager::RestartCurrentLevel() {
    if (levels.empty()) return;
    levels[currentLevelIndex]->Restart();
}
std::shared_ptr<DeveloperLevel> LevelManager::GetCurrentLevel() {
    if (currentLevelIndex < levels.size()) {
        return levels[currentLevelIndex];
    }
    return nullptr;
}
}  // namespace RogaliqueGame