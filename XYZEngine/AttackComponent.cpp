#include "pch.h"
#include "AttackComponent.h"

namespace XYZEngine
{
	void AttackComponent::Update(float deltaTime)
	{
	}
	void AttackComponent::Render()
	{
	}
	float AttackComponent::GetAttackPower() const
	{
		return attackPower;
	}
	void AttackComponent::SetAttackPower(float newAttackPower)
	{
		attackPower = newAttackPower;
	}
	void AttackComponent::Attack(GameObject* target)
	{
		if (!target)
		{
			return;
		}

		auto targetStatsComponent = target->GetComponent<StatsComponent>();
		if (targetStatsComponent)
		{
			float damage = attackPower;
			targetStatsComponent->TakeDamage(damage);
		}
	}

}
