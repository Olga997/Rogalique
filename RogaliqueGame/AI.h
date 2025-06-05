#pragma once
#include "CameraComponent.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "InputComponent.h"
#include "RenderSystem.h"
#include "SpriteRendererComponent.h"
#include "Vector.h"

namespace RogaliqueGame {
class AI {
   public:
    AI(const XYZEngine::Vector2Df& position, XYZEngine::GameObject* player);
    XYZEngine::GameObject* GetGameObject();

   private:
    XYZEngine::GameObject* gameObject;
};
}  // namespace RogaliqueGame