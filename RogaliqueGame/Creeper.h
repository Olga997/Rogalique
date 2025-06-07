#pragma once
#include "AI.h"

namespace RogaliqueGame
{
class Creeper : public AI {
   public:
    Creeper(XYZEngine::GameObject* player,
            sf::Color color);
    Creeper(const Creeper& other) : AI(other) {}

    std::unique_ptr<AI> Clone() const;

   private:
    float maxHealth = 100.f;
    float maxArmor = 50.f;
    float attackPower = 20.f;
};
}  // namespace RogaliqueGame