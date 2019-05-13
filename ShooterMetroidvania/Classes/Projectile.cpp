#include "Projectile.h"
namespace Sedna {

	Projectile::Projectile(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, cocos2d::Scene * scene, std::string spritePath)
		:GameObject(first,second,spritePath,scene)
	{

	}
}
