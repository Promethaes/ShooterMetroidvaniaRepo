#include "GameObject.h"
namespace Sedna {

	GameObject::GameObject(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, std::string spritePath, cocos2d::Scene * scene)
		:hitbox(new Hitbox(first,second,scene)),sprite(cocos2d::Sprite::create(spritePath))
	{
		scene->addChild(sprite);
	}
}
