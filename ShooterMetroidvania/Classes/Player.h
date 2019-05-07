#pragma once
#include "GameObject.h"
#include "Input.h"
#include "Events.h"

namespace Sedna {
	class Player : public GameObject {
	public:
		Player(const std::string spritePath, cocos2d::Scene* scene, const cocos2d::Vec2& first = cocos2d::Vec2(0.0f, 0.0f), const cocos2d::Vec2& second = cocos2d::Vec2(40.0f, 40.0f));

		void checkInput(float dt);

	private:

	};
}