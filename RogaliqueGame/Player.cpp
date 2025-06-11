#include "Player.h"

#include <AttackComponent.h>
#include <MovementComponent.h>
#include <ResourceSystem.h>
#include <SpriteColliderComponent.h>
#include <SpriteDirectionComponent.h>
#include <SpriteMovementAnimationComponent.h>
#include <StatsComponent.h>

#include "LevelManager.h"
#include "Logger.h"

namespace RogaliqueGame {
Player::Player(const XYZEngine::Vector2Df& position) {
    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Player");
    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(position);

    auto renderer =
        gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(
        *XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared(
            "player", 0));
    renderer->SetPixelSize(100, 100);

    auto camera = gameObject->AddComponent<XYZEngine::CameraComponent>();
    camera->SetWindow(&XYZEngine::RenderSystem::Instance()->GetMainWindow());
    camera->SetBaseResolution(1280, 720);

    auto input = gameObject->AddComponent<XYZEngine::InputComponent>();

    auto movement = gameObject->AddComponent<XYZEngine::MovementComponent>();
    movement->SetSpeed(400.f);

    auto spriteDirection =
        gameObject->AddComponent<XYZEngine::SpriteDirectionComponent>();

    auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(false);

    auto collider =
        gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
    collider->SetTrigger(false);

    auto animator =
        gameObject->AddComponent<XYZEngine::SpriteMovementAnimationComponent>();
    animator->Initialize("player", 6.f);

    auto health =
        gameObject->AddComponent<XYZEngine::StatsComponent>(100.0f, 50.0f);

    auto attackComponent =
        gameObject->AddComponent<XYZEngine::AttackComponent>(10.0f);
}

XYZEngine::GameObject* Player::GetGameObject() { return gameObject; }

void Player::SetupTriggerHandler() {
    auto collider =
        gameObject->GetComponent<XYZEngine::SpriteColliderComponent>();
    if (collider) {
        collider->SubscribeTriggerExit(
            [this](const XYZEngine::Trigger& trigger) {
                try {
                    this->HandleTriggerExit(trigger);
                } catch (const std::exception& e) {
                    LOG_ERROR("Exception in trigger exit handler: " +
                              std::string(e.what()));
                }
            });
    }
}

void Player::HandleTriggerExit(const XYZEngine::Trigger& trigger) {
    auto playerCollider =
        gameObject->GetComponent<XYZEngine::SpriteColliderComponent>();
    if (!playerCollider) {
        LOG_ERROR("Player collider component is missing");
        return;
    }

    XYZEngine::ColliderComponent* otherCollider = nullptr;
    if (trigger.first == playerCollider) {
        otherCollider = trigger.second;
    } else if (trigger.second == playerCollider) {
        otherCollider = trigger.first;
    }

    if (!otherCollider || !otherCollider->GetGameObject()) {
        LOG_ERROR("Invalid other collider in trigger");
        return;
    }

    LOG_INFO("Trigger with: " + otherCollider->GetGameObject()->GetName());

    if (otherCollider->GetGameObject()->GetName() == "PlaingZone") {
        LOG_INFO("Player entered PlaingZone - loading next level");
        LevelManager::Instance().LoadNextLevel();
    }
}
}  // namespace RogaliqueGame