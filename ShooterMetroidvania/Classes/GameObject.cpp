#include "GameObject.h"
namespace Sedna {

	GameObject::GameObject(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, std::string spritePath, cocos2d::Scene * scene)
		:hitbox(new Hitbox(first, second, scene)), sprite(cocos2d::Sprite::create(spritePath))
	{
		sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
		sprite->setPosition(hitbox->getNode()->getPosition());

		scene->addChild(sprite);
	}
	void GameObject::gameObjectUpdate(float dt)
	{
		if (hitbox->bottomLeft.y > 0)
			hitbox->addForce(cocos2d::Vec2(0, -0.98f), dt);
		else if (hitbox->bottomLeft.y <= 0) {
			hitbox->setForce(cocos2d::Vec2(hitbox->getVelocity().x, 0), dt);
			hitbox->bottomLeft.y = 0.0f;

		}
		hitbox->update(dt);
		sprite->setPosition((hitbox->bottomLeft + hitbox->topRight) / 2);

	}
}
