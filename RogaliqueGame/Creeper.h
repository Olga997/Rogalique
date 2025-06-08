#pragma once
#include "AI.h"

namespace RogaliqueGame {
class Creeper : public AI {
   public:
    Creeper(XYZEngine::GameObject* player, std::string enemyName, int id)
        : AI(player, enemyName, id) {
        SetColor(sf::Color::Red);
    };
    Creeper(const Creeper& other) : AI(other) {}

    std::unique_ptr<AI> Clone(XYZEngine::Vector2Df spawnPosition,
                              std::string enemyName, int id) const override;

   private:
};
}  // namespace RogaliqueGame