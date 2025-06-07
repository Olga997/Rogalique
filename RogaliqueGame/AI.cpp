#include "AI.h"

#include "AttackComponent.h"
#include "FollowComponent.h"
#include "ResourceSystem.h"
#include "SpriteColliderComponent.h"
#include "SpriteDirectionComponent.h"
#include "SpriteMovementAnimationComponent.h"
#include "StatsComponent.h"
#include "SpriteRendererComponent.h"

namespace RogaliqueGame {

    AI::AI( XYZEngine::GameObject* player, sf::Color color) 
    {

    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("AI");   

    auto renderer =
        gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(
        *XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("AI",0));
    renderer->SetTextureColor(color);
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
    std::unique_ptr<AI> AI::Clone() { return std::make_unique<AI>(*this); }

    void AI::SetPosition(const XYZEngine::Vector2Df& spawnPosition)
    {
        auto transform =
        gameObject->GetComponent<XYZEngine::TransformComponent>();
        transform->SetWorldPosition(spawnPosition);
    }

    XYZEngine::Vector2Df AI::GetPosition()
    { 
       auto transform =  gameObject->GetComponent<XYZEngine::TransformComponent>();
        auto spawnPosition = transform->GetWorldPosition();
        return spawnPosition; 
    }
 

    }  // namespace RogaliqueGame
