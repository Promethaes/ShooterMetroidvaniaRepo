#include "Hitbox.h"
namespace Sedna {

	Hitbox::Hitbox(const cocos2d::Vec2& first, const cocos2d::Vec2& second, cocos2d::Scene * scene)
		:bottomLeft(first),topRight(second)
	{
		node = cocos2d::DrawNode::create();
		node->drawRect(bottomLeft, topRight, cocos2d::Color4F(1.0f,0.0f,0.0f,1.0f));
		scene->addChild(node,100);

	}
	void Hitbox::addForce(const cocos2d::Vec2 & v, float dt)
	{
		velocity += v * dt;
	}
	void Hitbox::update(float dt)
	{
		bottomLeft += velocity;
		topRight += velocity;

		node->clear();
		node->drawRect(bottomLeft, topRight, cocos2d::Color4F(1.0f, 0.0f, 0.0f, 1.0f));

	}
	bool Hitbox::checkCollision(const Hitbox & other)
	{
		//auto centre = (bottomLeft + topRight) / 2;
		//auto otherCentre = (other.bottomLeft + other.topRight) / 2;
		//
		//auto rightMost = centre + cocos2d::Vec2(topRight.x,0);
		//auto leftMost = centre - cocos2d::Vec2(bottomLeft.x, 0);
		//
		//auto topMost = centre + cocos2d::Vec2(0, topRight.y);
		//auto bottomMost = centre - cocos2d::Vec2(0, bottomLeft.y);

		if (topRight.x >= other.bottomLeft.x && bottomLeft.x <= other.topRight.x&&
			topRight.y >= other.bottomLeft.y && bottomLeft.y <= other.topRight.y)
			return true;
		return false;
	}
}
