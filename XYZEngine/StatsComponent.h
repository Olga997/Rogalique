#pragma once
#include "Component.h"
#include "GameObject.h"

namespace XYZEngine
{
	class StatsComponent : public Component
	{
	public:
		StatsComponent(GameObject* gameObject, float health, float armor)
			:Component(gameObject), maxHealth(health), currentHealth(health), armor(armor)
		{
		}
			
		void Update(float deltaTime) override;
		void Render() override;

		float GetCurrentHealth() const { return currentHealth; }
		float GetMaxHealth() const { return maxHealth; }
		float GetArmor() const { return armor; }

		void TakeDamage(float damage);
		void Heal(float amount);
	
	private:
		float maxHealth;
		float currentHealth;
		float armor;
	};
}