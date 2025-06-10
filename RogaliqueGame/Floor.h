#pragma once

#include <GameWorld.h>
#include <ResourceSystem.h>
#include <SpriteRendererComponent.h>

#include "GameObject.h"

namespace RogaliqueGame {
class Floor {
   public:
    Floor(const XYZEngine::Vector2Df& position, int textureMapIndex);
    void SetColor(sf::Color color);
   private:
    XYZEngine::GameObject* gameObject;
};
}  // namespace RogaliqueGame