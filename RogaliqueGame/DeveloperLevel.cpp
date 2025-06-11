#include "DeveloperLevel.h"

#include <ColliderComponent.h>

#include "Creeper.h"
#include "LevelManager.h"
#include "MazeGenerator.h"
#include "Wall.h"

using namespace XYZEngine;

namespace RogaliqueGame {

DeveloperLevel::DeveloperLevel(int width, int height, int enemyCount,
                               sf::Color levelColor)
    : width_(width),
      height_(height),
      enemyCount_(enemyCount),
      levelColor_(levelColor) {}

void DeveloperLevel::Start() {
    for (int y = 0; y < height_ + 1; y++) {
        for (int x = 0; x < width_ + 1; x++) {
            // if not wall place
            if (x != 0 && x != width_ && y != 0 && y != height_) {
                floors.push_back(std::make_unique<Floor>(
                    std::forward<XYZEngine::Vector2Df>({x * 128.f, y * 128.f}),
                    std::forward<int>(0)));
            }
        }
    }

    // Maze Generator
    MazeGenerator mazeGenerator(width_, height_, this);
    mazeGenerator.Generate();

    // Create TriggerBox around the scene like plaing zone

    for (int i = 0; i < floors.size(); i++) {
        floors[i]->SetColor(levelColor_);
    }

    // Set different color to level
    for (int i = 0; i < floors.size(); i++) {
        floors[i]->SetColor(levelColor_);
    }
    for (int i = 0; i < walls.size(); i++) {
        walls[i]->SetColor(levelColor_);
    }
    player = std::make_shared<Player>(std::forward<XYZEngine::Vector2Df>(
        {width_ / 2 * 128.f, height_ / 2 * 128.f}));

    plaingZone = std::make_shared<PlaingZone>(width_ * 128, height_ * 128);

    player->SetupTriggerHandler();

    music = std::make_unique<Music>("music");

    // Создание спавнера с криперами
    std::shared_ptr<Spawner> creeperSpawner = std::make_unique<Spawner>(
        std::forward<XYZEngine::Vector2Df>(
            {width_ / 3 * 128.f, height_ / 3 * 128.f}),
        enemyCount_,
        std::make_unique<Creeper>(player->GetGameObject(), "Creeper", 0));

    creeperSpawner->Spawn();
}
void DeveloperLevel::Restart() {
    Stop();
    Start();
}
void DeveloperLevel::Stop() { GameWorld::Instance()->Clear(); }

}  // namespace RogaliqueGame