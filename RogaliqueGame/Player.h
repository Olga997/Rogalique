#pragma once

#include "CameraComponent.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "InputComponent.h"
#include "RenderSystem.h"
#include "SpriteRendererComponent.h"

namespace RogaliqueGame {
class Player {
   public:
    Player(const XYZEngine::Vector2Df& position);
    XYZEngine::GameObject* GetGameObject();

   private:
    XYZEngine::GameObject* gameObject;
};
}  // namespace RogaliqueGame