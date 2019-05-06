#pragma once
#include "cocos2d.h"
namespace Sedna {

	class Hitbox {
	public:
		Hitbox(const cocos2d::Vec2 &first, const cocos2d::Vec2& second, cocos2d::Scene* scene);


		cocos2d::DrawNode* getNode() const { return node; }
	private:
		cocos2d::Vec2 bottomLeft;
		cocos2d::Vec2 topRight;

		cocos2d::DrawNode* node;
	};
}