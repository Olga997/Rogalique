#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Collidable.h"

namespace ArkanoidGame
{
	class Ball;

	class Platform: public GameObject, public Collidable
	{
	public:
		Platform(const sf::Vector2f& position);
		~Platform() = default;
		void Update(float timeDelta) override;
	
		bool GetCollision(std::shared_ptr<Collidable> collidable) const override;
		void OnHit() override {}
		bool CheckCollision(std::shared_ptr<Collidable> collidable) override;
		void ChangeWidth(float multiplyWidth);

	private:
		void Move(float speed);
	};
}
