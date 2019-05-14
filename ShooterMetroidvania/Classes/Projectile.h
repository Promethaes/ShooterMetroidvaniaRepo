#pragma once
#include "GameObject.h"

namespace Sedna {

	class Projectile : public GameObject {
	public:
		Projectile(const cocos2d::Vec2& first, const cocos2d::Vec2& second, cocos2d::Scene* scene, std::string spritePath = "CloseSelected.png");
		Projectile(cocos2d::Scene* scene, std::string spritePath = "CloseSelected.png");
		void gameObjectUpdate(float dt) override;
	private:

	};
}