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
	void Projectile::gameObjectUpdate(float dt)
	{
		if (hitbox->getNode()->getPosition().y > Floor)
			hitbox->addForce(cocos2d::Vec2(0, -6.5f), dt);
		else if (hitbox->getNode()->getPosition().y - hitbox->topRight.y <= Floor) {

			hitbox->getNode()->setPosition(hitbox->getNode()->getPosition().x, Floor);

		}
		hitbox->update(dt);
		sprite->setPosition(hitbox->getNode()->getPosition());
	}
}
