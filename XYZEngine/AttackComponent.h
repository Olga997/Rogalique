#pragma once
#include "Component.h"
#include "GameObject.h"
#include "StatsComponent.h"

namespace XYZEngine
{
	class AttackComponent : public Component
	{
	public:
		AttackComponent(GameObject* gameObject, float attackPower)
			:Component(gameObject), attackPower(attackPower)
		{

		}
		void Update(float deltaTime) override;
		void Render() override;

		float GetAttackPower() const;
		void SetAttackPower(float newAttackPower);		
		void Attack(GameObject* target);	

	private:

		float attackPower;
	};
}

