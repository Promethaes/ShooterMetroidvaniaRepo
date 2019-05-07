#include "Player.h"
namespace Sedna {

	Player::Player(const std::string spritePath, cocos2d::Scene * scene, const cocos2d::Vec2 & first, const cocos2d::Vec2 & second)
		:GameObject(first,second,spritePath,scene)
	{

	}
	void Player::checkInput(float dt)
	{
		if (isEvent(Events::W))
			hitbox->addForce(cocos2d::Vec2(0, 5.0f), dt);
		if (isEvent(Events::S))
			hitbox->addForce(cocos2d::Vec2(0, -5.0f), dt);
		if (isEvent(Events::A))
			hitbox->addForce(cocos2d::Vec2(-5.0f, 0), dt);
		if(isEvent(Events::D))
			hitbox->addForce(cocos2d::Vec2(5.0f, 0), dt);
	}
}
