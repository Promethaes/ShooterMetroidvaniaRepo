#include "GameObject.h"
namespace Sedna {

	std::vector<GameObject*> GameObject::gameObjects = {};
	GameObject::GameObject(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, std::string spritePath, cocos2d::Scene * scene)
		:hitbox(new Hitbox(first, second, scene)), sprite(cocos2d::Sprite::create(spritePath))
	{
		sprite->setPosition(hitbox->getNode()->getPosition());

		scene->addChild(sprite);
		gameObjects.push_back(this);
	}

	//use this constructor if you want to have the size of the hitbox be the size of the sprite
	GameObject::GameObject(std::string spritePath, cocos2d::Scene * scene)
		:sprite(cocos2d::Sprite::create(spritePath))
	{
		hitbox = new Hitbox(cocos2d::Vec2(sprite->getBoundingBox().getMinX(), sprite->getBoundingBox().getMinY()), cocos2d::Vec2(sprite->getBoundingBox().getMaxX(), sprite->getBoundingBox().getMaxY()), scene);

		sprite->setPosition(hitbox->getNode()->getPosition());

		scene->addChild(sprite);
		gameObjects.push_back(this);
	}
	void GameObject::gameObjectUpdate(float dt)
	{
		if (hitbox->getNode()->getPosition().y > Floor)
			hitbox->addForce(cocos2d::Vec2(0, -6.5f), dt);
		else if (hitbox->getNode()->getPosition().y - hitbox->topRight.y <= Floor) {
			hitbox->velocity.y = 0.0f;

			hitbox->getNode()->setPosition(hitbox->getNode()->getPosition().x, Floor);

		}
		hitbox->update(dt);
		sprite->setPosition(hitbox->getNode()->getPosition());

	}
}
