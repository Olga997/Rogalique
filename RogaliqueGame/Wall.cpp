#include "Wall.h"
#include <SpriteColliderComponent.h>

namespace RogaliqueGame {
Wall::Wall(const XYZEngine::Vector2Df position, int textureMapIndex) {
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Wall");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer =
        gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(
        *XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared(
            "level_walls", textureMapIndex));
    renderer->SetPixelSize(128, 128);

    auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(true);

    auto collider =
        gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
}

void Wall::SetColor(sf::Color color) {
    auto renderer =
        gameObject->GetComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTextureColor(color);
}
}  // namespace RogaliqueGame