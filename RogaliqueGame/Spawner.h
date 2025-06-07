#pragma once
#include "AI.h"

using namespace XYZEngine;

namespace RogaliqueGame {


class Spawner {
   public:
    Spawner(const XYZEngine::Vector2Df& spawnPosition);

    ~Spawner() = default;

    void Spawn(int enemyCount, std::unique_ptr<AI> prototype);

    void SetEnemyCount(int count);
    void SetEnemyProtoripe(std::unique_ptr<AI> newPrototype);

   private:
    int enemyCount;
    const XYZEngine::Vector2Df position;
    std::vector<std::unique_ptr<AI>> enemies;
    std::unique_ptr<AI> prototype;

};
}  // namespace RogaliqueGame
