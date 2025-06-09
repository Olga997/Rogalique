#include "Spawner.h"

#include "Logger.h"

namespace RogaliqueGame {
Spawner::Spawner(const XYZEngine::Vector2Df& spawnPosition, int enemyCount,
                 std::unique_ptr<AI> prototype)
    : position(spawnPosition),
      enemyCount(enemyCount),
      prototype_(std::move(prototype)) {
    LOG_INFO(prototype_->GetGameObject()->GetName());
}
void Spawner::Spawn() {
    enemies.clear();

    for (int i = 0; i < enemyCount - 1; i++) {
        XYZEngine::Vector2Df newPosition = {position.x - 128 * i + 1,
                                            position.y - 128 * i + 1};
        auto newEnemy = prototype_->Clone(newPosition, "Clone", i);
        LOG_INFO("Creeper spawn " + std::to_string(newEnemy->GetPosition().x) +
                 "  " + newEnemy->GetGameObject()->GetName());
        enemies.push_back(std::move(newEnemy));
    }
}

void Spawner::SetEnemyCount(int count) { enemyCount = count; }

void Spawner::SetEnemyPrototipe(std::unique_ptr<AI> newPrototype) {
    prototype_ = std::move(newPrototype);
}

}  // namespace RogaliqueGame
// namespace RogaliqueGame