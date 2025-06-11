#include "PlaingZone.h"

#include <GameWorld.h>
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>

namespace RogaliqueGame {
PlaingZone::PlaingZone(int width, int heigh) {
    gameObject =
        XYZEngine::GameWorld::Instance()->CreateGameObject("PlaingZone");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(width / 2, heigh / 2);

    auto renderer =
        gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(
        *XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared(
            "level_floors", 0));
    renderer->SetPixelSize(width, heigh);
    renderer->SetTextureColor(sf::Color::Color(0, 0, 0, 0));

    auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(true);

    auto collider =
        gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
    collider->SetTrigger(true);
}
}  // namespace RogaliqueGame