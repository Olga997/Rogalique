#pragma once

#include <GameWorld.h>
#include <SpriteRendererComponent.h>
#include <ResourceSystem.h>
#include "GameObject.h"

namespace RogaliqueGame
{
	class Floor
	{
	public:
		Floor(const XYZEngine::Vector2Df& position, int textureMapIndex);
	private:
		XYZEngine::GameObject* gameObject;
	};
}