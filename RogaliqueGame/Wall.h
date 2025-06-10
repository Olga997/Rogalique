#pragma once

#include <GameWorld.h>
#include <ResourceSystem.h>

#include "GameObject.h"

namespace RogaliqueGame {
class Wall {
   public:
    Wall(const XYZEngine::Vector2Df position, int textureMapIndex);
    void SetColor(sf::Color color);
   private:
    XYZEngine::GameObject* gameObject;
};
}  // namespace RogaliqueGame
