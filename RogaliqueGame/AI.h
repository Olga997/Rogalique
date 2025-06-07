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
    AI(XYZEngine::GameObject* player,
       sf::Color color);
    XYZEngine::GameObject* GetGameObject();
    std::unique_ptr<AI> Clone();
    void SetPosition(const XYZEngine::Vector2Df& spawnPosition);
    XYZEngine::Vector2Df GetPosition();

   private:
    XYZEngine::GameObject* gameObject;
    float maxHealth = 0.f; 
    float maxArmor=0.f;     
    float attackPower=0.f;
};
}  // namespace RogaliqueGame