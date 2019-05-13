#pragma once
#include "cocos2d.h"
namespace Sedna {

	class Hitbox {
	public:
		Hitbox(const cocos2d::Vec2 &first, const cocos2d::Vec2& second, cocos2d::Scene* scene);


		void setForce(const cocos2d::Vec2&, float dt);
		void addForce(const cocos2d::Vec2& v, float dt);
		void update(float dt);

		bool checkCollision(const Hitbox& other);
		cocos2d::DrawNode* getNode() const { return node; }
		
		cocos2d::Vec2 getCentre() const { return (bottomLeft + topRight) / 2.0f; }

		cocos2d::Vec2 bottomLeft;
		cocos2d::Vec2 topRight;
		cocos2d::Vec2 velocity;
	private:



		cocos2d::DrawNode* node;
	};
}