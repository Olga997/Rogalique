#include "AI.h"

#include "AttackComponent.h"
#include "FollowComponent.h"
#include "ResourceSystem.h"
#include "SpriteColliderComponent.h"
#include "SpriteDirectionComponent.h"
#include "SpriteMovementAnimationComponent.h"
#include "StatsComponent.h"

namespace RogaliqueGame {
RogaliqueGame::AI::AI(const XYZEngine::Vector2Df& position,
                      XYZEngine::GameObject* player) {
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("AI");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer =
        gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(
        *XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("AI",
                                                                           0));
    renderer->SetPixelSize(100, 100);

    auto follower = gameObject->AddComponent<XYZEngine::FollowComponent>();
    follower->SetTarget(player);
    follower->SetSpeed(120.f);

    auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(false);
    auto collider =
        gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();

    auto health =
        gameObject->AddComponent<XYZEngine::StatsComponent>(100.f, 50.f);

    auto attackComponent =
        gameObject->AddComponent<XYZEngine::AttackComponent>(10.f);
}

XYZEngine::GameObject* AI::GetGameObject() { return gameObject; }
}  // namespace RogaliqueGame
