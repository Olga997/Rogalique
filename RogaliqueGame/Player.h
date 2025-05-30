#pragma once

#include "CameraComponent.h"
#include "GameWorld.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "InputComponent.h"
#include "GameObject.h"

namespace RogaliqueGame
{
	class Player
	{
	public:
		Player(const XYZEngine::Vector2Df& position);
		XYZEngine::GameObject* GetGameObject();

	private:
		XYZEngine::GameObject* gameObject;
	};
}