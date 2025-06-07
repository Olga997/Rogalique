#include "Spawner.h"
#include "Logger.h"

namespace RogaliqueGame {
Spawner::Spawner(const XYZEngine::Vector2Df& spawnPosition)
    :  position(spawnPosition) {

}
void Spawner::Spawn(int enemyCount, std::unique_ptr<AI> prototype) {
    enemies.clear();

    for (int i = 0; i < enemyCount; i++) 
    {
        auto newEnemy = prototype->Clone();       

        XYZEngine::Vector2Df newPosition = {position.x - 10 * i + 1,
                                            position.y - 10 * i + 1};
        newEnemy->SetPosition(newPosition);    

        LOG_INFO("Creeper spawn " + std::to_string(newEnemy->GetPosition().x));

        enemies.push_back(std::move(newEnemy));       

    }
    LOG_INFO(std::to_string(enemies.size()));
}



void Spawner::SetEnemyCount(int count) { enemyCount = count; }

void Spawner::SetEnemyProtoripe(std::unique_ptr<AI> newPrototype) 
{
    prototype = std::move(newPrototype);
}

}  // namespace RogaliqueGame