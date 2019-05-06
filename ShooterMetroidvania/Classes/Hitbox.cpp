#include "Hitbox.h"
namespace Sedna {

	Hitbox::Hitbox(const cocos2d::Vec2& first, const cocos2d::Vec2& second, cocos2d::Scene * scene)
		:bottomLeft(first),topRight(second)
	{
		node = cocos2d::DrawNode::create();
		node->drawRect(bottomLeft, topRight, cocos2d::Color4F(1.0f,0.0f,0.0f,1.0f));
		scene->addChild(node);
	}
}
