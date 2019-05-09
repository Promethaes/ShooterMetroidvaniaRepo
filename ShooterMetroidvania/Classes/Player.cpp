#include "Player.h"
namespace Sedna {

	Player::Player(const std::string spritePath, cocos2d::Scene * scene, const cocos2d::Vec2 & first, const cocos2d::Vec2 & second)
		:GameObject(first, second, spritePath, scene)
	{

	}
	void Player::gameObjectUpdate(float dt)
	{
		if (hitbox->getNode()->getPosition().y > 20.0f)
			hitbox->addForce(cocos2d::Vec2(0, -3.0f), dt);
		else if (hitbox->getNode()->getPosition().y - hitbox->topRight.y <= 20.0f) {
			if (!isEvent(Events::W))
				hitbox->setForce(cocos2d::Vec2(hitbox->getVelocity().x, 0), dt);

			hitbox->getNode()->setPosition(hitbox->getNode()->getPosition().x, 20.0f);

		}
		hitbox->update(dt);
		sprite->setPosition(hitbox->getNode()->getPosition());
	}
	void Player::checkInput(float dt)
	{
		if (isEvent(Events::W))
			hitbox->addForce(cocos2d::Vec2(0, 5.0f), dt);
		else if (isEvent(Events::S))
			hitbox->addForce(cocos2d::Vec2(0, -5.0f), dt);


		if (isEvent(Events::A))
			hitbox->addForce(cocos2d::Vec2(-5.0f, 0), dt);
		else if (isEvent(Events::D))
			hitbox->addForce(cocos2d::Vec2(5.0f, 0), dt);
	}
}
