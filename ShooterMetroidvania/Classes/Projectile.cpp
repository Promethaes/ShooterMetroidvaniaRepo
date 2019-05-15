#include "Projectile.h"
#include "Events.h"
#include "Input.h"
namespace Sedna {

	Projectile::Projectile(const cocos2d::Vec2 & first, const cocos2d::Vec2 & second, cocos2d::Scene * scene, std::string spritePath)
		:GameObject(first, second, spritePath, scene)
	{

	}
	Projectile::Projectile(cocos2d::Scene * scene, std::string spritePath)
		: GameObject(spritePath, scene)
	{
	}
	
}
