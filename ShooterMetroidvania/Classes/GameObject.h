#pragma once
#include "Hitbox.h"
#include <vector>
#include <string>
//may or may not be a sedna product...we'll see
namespace Sedna {

	class GameObject {
	public:
		GameObject(const cocos2d::Vec2& first, const cocos2d::Vec2& second, std::string spritePath, cocos2d::Scene* scene);


		virtual void gameObjectUpdate(float dt);

		cocos2d::Sprite* getSprite() const { return sprite; }
		Hitbox* getHitbox() const { return hitbox; }
		static std::vector<Sedna::GameObject*> gameObjects;
	protected:

		Hitbox* hitbox;
		cocos2d::Sprite* sprite;
	};

}