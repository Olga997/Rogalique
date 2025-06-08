#include "Creeper.h"

namespace RogaliqueGame {
std::unique_ptr<AI> Creeper::Clone(XYZEngine::Vector2Df spawnPosition,
                                   std::string enemyName, int id) const {
    auto clonedCreeper = std::make_unique<Creeper>(fallowTarget, enemyName, id);
    clonedCreeper->SetPosition(spawnPosition);
    return clonedCreeper;
}
}  // namespace RogaliqueGame
