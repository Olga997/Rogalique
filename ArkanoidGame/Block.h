#pragma once
#include "Ball.h"
#include "GameObject.h"
#include "Collidable.h"
#include "IDelayedAction.h"
#include "IObserver.h"

namespace ArkanoidGame
{
	class Block : public GameObject, public Collidable, public IObservable
	{		
	protected:
		void OnHit();
		int hitCount = 1;
	public:		
		Block(const sf::Vector2f& position, const sf::Color& color);
		virtual ~Block();
		bool GetCollision(std::shared_ptr<Collidable> collidable) const override;
		void Update(float timeDelta) override;
		bool IsBroken();
		virtual int GetScorePoint()=0;
	};


	class SmoothDestroyableBlock : public Block, public IDelayedAction
	{
	protected:
		void OnHit() override;
		sf::Color color;
	public:
		SmoothDestroyableBlock(const sf::Vector2f& position, const sf::Color& color = sf::Color::Green);
		~SmoothDestroyableBlock() = default;
		void Update(float timeDelta) override;

		bool GetCollision(std::shared_ptr<Collidable> collidableObject) const override;
		void FinalAction() override;
		void EachTickAction(float deltaTime) override;
		int GetScorePoint()override;
	};


	class UnbreackableBlock : public Block
	{
	public:
		UnbreackableBlock(const sf::Vector2f& position);
		void OnHit() override;
		void Update(float) {
			int i = 0;
			++i;
		};
		int GetScorePoint()override;
	};


	class TwoHitBlock : public SmoothDestroyableBlock
	{
	public:
		TwoHitBlock(const sf::Vector2f& position);
	private:
		void OnHit() override;
		void StageChange();
		int GetScorePoint()override;
	};
}