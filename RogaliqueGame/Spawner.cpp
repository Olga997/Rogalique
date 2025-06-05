#include "Spawner.h"

namespace RogaliqueGame {
Spawner::Spawner(int enemyCount, AI* enemyType)
    : enemyCount(enemyCount), prototype(std::move(prototype)) {}

void Spawner::Spawn() {
    enemies.clear();

    for (int i = 0; i < enemyCount; i++) 
    {
        enemies.push_back(prototype);
    }
}

void Spawner::SetEnemyCount(int count) { enemyCount = count; }

void Spawner::SetEnemyProtoripe(std::shared_ptr<AI> prototype) {
    prototype = std::move(prototype);
}

}  // namespace RogaliqueGame