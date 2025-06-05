#pragma once
#include "AI.h"


namespace RogaliqueGame 
{

class Spawner 
{
   public:
    Spawner(int enemyCount, AI* enemyType);
    ~Spawner() = default;

    void Spawn();

    void SetEnemyCount(int count);
    void SetEnemyProtoripe(std::shared_ptr<AI> prototype);

   private:
    int enemyCount;
    std::vector<std::shared_ptr<AI>> enemies;
    std::shared_ptr<AI> prototype;
};
}

