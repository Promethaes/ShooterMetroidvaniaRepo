#include "GameObject.h"
namespace Sedna {

	std::vector<GameObject> GameObject::gameObjects = {};
	GameObject::GameObject(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, std::string spritePath, cocos2d::Scene * scene)
		:hitbox(new Hitbox(first,second,scene)),sprite(cocos2d::Sprite::create(spritePath))
	{
		sprite->setAnchorPoint(cocos2d::Vec2(0.5f,0.5f));
		sprite->setPosition((hitbox->bottomLeft + hitbox->topRight) / 2);

		scene->addChild(sprite);
		gameObjects.push_back(*this);
	}
	void GameObject::gameObjectUpdate(float dt)
	{
		if(hitbox->bottomLeft.y > 0)
		hitbox->addForce(cocos2d::Vec2(0, 6), dt);
		if (hitbox->bottomLeft.y <= 0)
			hitbox->bottomLeft.y = 0;
		hitbox->update(dt);
		sprite->setPosition((hitbox->bottomLeft + hitbox->topRight) / 2);
	
	}
}
