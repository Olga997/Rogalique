#include "pch.h"
#include "StatsComponent.h"
#include "Logger.h"

namespace XYZEngine
{
	void StatsComponent::Update(float deltaTime)
	{

	}

	void StatsComponent::Render()
	{

	}

	void StatsComponent::TakeDamage(float damage)
	{
		damage -= armor;
		if (damage < 0)
		{
			damage = 0;
		}
		armor -= 1;
		if (armor < 0)
		{
			armor = 0;
			LOG_INFO("The armor was broken");
		}

		currentHealth -= damage;
		if (currentHealth < 0)
		{
			currentHealth = 0;
		}
		LOG_INFO("Healed" + std::to_string(damage) + " damage, current health: " + std::to_string(currentHealth));
	}

	void StatsComponent::Heal(float amount)
	{
		currentHealth += amount;
		if (currentHealth > maxHealth)
		{
			currentHealth = maxHealth;
		}
		LOG_INFO("Healed" + std::to_string(amount) + " amount, current health: " + std::to_string(currentHealth));
	}


}