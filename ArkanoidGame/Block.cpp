#include "Block.h"
#include "Sprite.h"
#include "GameSettings.h"
#include <assert.h>


namespace ArkanoidGame
{
	Block::Block(const sf::Vector2f& position, const sf::Color& color)
		: GameObject(SETTINGS.TEXTURES_PATH + "block.png", position, SETTINGS.BLOCK_WIDTH, SETTINGS.BLOCK_HEIGHT)
	{
		sprite.setColor(color);
	}
	Block::~Block()
	{

	}
	bool Block::GetCollision(std::shared_ptr<Collidable> collidable) const {
		auto gameObject = std::dynamic_pointer_cast<GameObject>(collidable);
		assert(gameObject);
		sf::Rect rect = gameObject->GetRect();
		rect.width *= 1.1;
		return GetRect().intersects(gameObject->GetRect());
	}

	void Block::OnHit()
	{
		hitCount = 0;
		Emit();
	}

	bool Block::IsBroken()
	{
		return hitCount <= 0;
	}
	void Block::Update(float timeDelta)
	{

	}

	SmoothDestroyableBlock::SmoothDestroyableBlock(const sf::Vector2f& position, const sf::Color& color)
		: Block (position, color), color(color)

	{

	}
	void SmoothDestroyableBlock::Update(float timeDelta)
	{
		UpdateTimer(timeDelta);
	}

	bool SmoothDestroyableBlock::GetCollision(std::shared_ptr<Collidable> collidable) const {
		if (isTimerStarted_) {
			return false;
		}

		auto gameObject = std::dynamic_pointer_cast<GameObject>(collidable);
		assert(gameObject);
		sf::Rect rect = gameObject->GetRect();
		rect.width *= 1.1f;
		return GetRect().intersects(gameObject->GetRect());
	}

	void SmoothDestroyableBlock::OnHit()
	{
		StartTimer(SETTINGS.BREAK_DELAY);
	}

	void SmoothDestroyableBlock::FinalAction()
	{
		--hitCount;
		Emit();
	}

	void SmoothDestroyableBlock::EachTickAction(float deltaTime)
	{
		color.a = 255 * currentTime_ / destroyTime_;
		sprite.setColor(color);
	}

	int SmoothDestroyableBlock::GetScorePoint()
	{
		return 10;
	}

	UnbreackableBlock::UnbreackableBlock(const sf::Vector2f& position)
		: Block(position, sf::Color::Color(105, 105, 105))
	{

	}

	void UnbreackableBlock::OnHit() {
		//--hit_count ;
	}

	int UnbreackableBlock::GetScorePoint()
	{
		return 0;
	}

	TwoHitBlock::TwoHitBlock(const sf::Vector2f& position)
		: SmoothDestroyableBlock(position, sf::Color::Color(0,255,140))
	{
		hitCount = 2;
	}

	void TwoHitBlock::OnHit() {
		--hitCount;
		StageChange();

		if (hitCount == 0) {
			hitCount = 1;
			StartTimer(SETTINGS.BREAK_DELAY);
		}
	}

	void TwoHitBlock::StageChange()
	{		
		if (hitCount == 1) 
		{
			sprite.setColor(sf::Color::Green);
			color = sf::Color::Green;
		}
	}
	int TwoHitBlock::GetScorePoint()
	{
		return 20;
	}
}
