#include "AI.h"

#include "AttackComponent.h"
#include "FollowComponent.h"
#include "ResourceSystem.h"
#include "SpriteColliderComponent.h"
#include "SpriteDirectionComponent.h"
#include "SpriteMovementAnimationComponent.h"
#include "SpriteRendererComponent.h"
#include "StatsComponent.h"

namespace RogaliqueGame {

AI::AI(XYZEngine::GameObject* player, std::string enemyName, int id)
    : fallowTarget(player) {
    std::string name = enemyName + "_" + std::to_string(id);
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject(name);

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

    auto health = gameObject->AddComponent<XYZEngine::StatsComponent>(maxHealth,
                                                                      maxArmor);

    auto attackComponent =
        gameObject->AddComponent<XYZEngine::AttackComponent>(attackPower);
}

XYZEngine::GameObject* AI::GetGameObject() { return gameObject; }

std::unique_ptr<AI> AI::Clone(XYZEngine::Vector2Df spawnPosition,
                              std::string enemyName, int id) const {
    auto clonedAI = std::make_unique<AI>(fallowTarget, enemyName, id);
    clonedAI->SetPosition(spawnPosition);
    clonedAI->SetColor(sf::Color::Blue);
    return clonedAI;
}
void AI::SetPosition(const XYZEngine::Vector2Df& spawnPosition) {
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(spawnPosition);
}
void AI::SetColor(sf::Color color) {
    auto renderer =
        gameObject->GetComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTextureColor(color);
}

XYZEngine::Vector2Df AI::GetPosition() {
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    auto spawnPosition = transform->GetWorldPosition();
    return spawnPosition;
}

}  // namespace RogaliqueGame
