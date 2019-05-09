#pragma once
#include "GameObject.h"
#include "Input.h"
#include "Events.h"

namespace Sedna {
	class Player : public GameObject {
	public:
		Player(const std::string spritePath, cocos2d::Scene* scene, const cocos2d::Vec2& first = cocos2d::Vec2(20.0f, 20.0f), const cocos2d::Vec2& second = cocos2d::Vec2(60.0f, 60.0f));

		void gameObjectUpdate(float dt) override;
		void checkInput(float dt);

	private:

	};
}