#include "Floor.h"

#include <SpriteColliderComponent.h>

namespace RogaliqueGame {
Floor::Floor(const XYZEngine::Vector2Df& position, int textureMapIndex) {
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Floor");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer =
        gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(
        *XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared(
            "level_floors", textureMapIndex));
    renderer->SetPixelSize(128, 128);
}
void Floor::SetColor(sf::Color color) {
    auto renderer =
        gameObject->GetComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTextureColor(color);
}
}  // namespace RogaliqueGame