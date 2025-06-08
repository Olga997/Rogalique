#pragma once
#include "CameraComponent.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "InputComponent.h"
#include "RenderSystem.h"
#include "Vector.h"

namespace RogaliqueGame {
class AI {
   public:
    AI(XYZEngine::GameObject* player, std::string enemyName, int id);
    XYZEngine::GameObject* GetGameObject();
    virtual std::unique_ptr<AI> Clone(XYZEngine::Vector2Df spawnPosition,
                                      std::string enemyName, int id) const;
    void SetPosition(const XYZEngine::Vector2Df& spawnPosition);
    void SetColor(sf::Color color);
    XYZEngine::Vector2Df GetPosition();
    XYZEngine::GameObject* fallowTarget;

   private:
    XYZEngine::GameObject* gameObject;

    float maxHealth = 0.f;
    float maxArmor = 0.f;
    float attackPower = 0.f;
};
}  // namespace RogaliqueGame