#include "GameObject.h"
namespace Sedna {
	
	std::vector<GameObject*> GameObject::gameObjects = {};
	GameObject::GameObject(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, std::string spritePath, cocos2d::Scene * scene)
		:hitbox(new Hitbox(first, second, scene)), sprite(cocos2d::Sprite::create(spritePath))
	{
		sprite->setAnchorPoint(cocos2d::Vec2(0, 0));
		sprite->setPosition(hitbox->getNode()->getPosition());

		scene->addChild(sprite);
		gameObjects.push_back(this);
	}
	void GameObject::gameObjectUpdate(float dt)
	{
		if (hitbox->getNode()->getPosition().y > 20.0f)
			hitbox->addForce(cocos2d::Vec2(0, -6.5f), dt);
		else if (hitbox->getNode()->getPosition().y - hitbox->topRight.y <= 20.0f) {
				hitbox->velocity.y = 0.0f;

			hitbox->getNode()->setPosition(hitbox->getNode()->getPosition().x, 20.0f);

		}
		hitbox->update(dt);
		sprite->setPosition(hitbox->getNode()->getPosition());

	}
}
