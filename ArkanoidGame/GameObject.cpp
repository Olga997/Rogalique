#include "GameObject.h"
#include "Sprite.h"
#include <assert.h>

namespace RogaliqueGame
{
	GameObject::GameObject(const std::string& texturePath, const sf::Vector2f& position, float width, float height)
	{
		assert(texture.loadFromFile(texturePath));

		InitSprite(sprite, width, height, texture);
		sprite.setPosition(position);
	}
	void RogaliqueGame::GameObject::Draw(sf::RenderWindow& window)
	{
		DrawSprite(sprite, window);
	}
	void GameObject::restart()
	{
		sprite.setPosition(startPosition);
	}
}
