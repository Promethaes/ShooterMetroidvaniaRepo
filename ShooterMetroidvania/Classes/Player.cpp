#include <iostream>
#include "Player.h"
#include "MouseListner.h"
namespace Sedna {

	Player::Player(const std::string spritePath, cocos2d::Scene * scene, const cocos2d::Vec2 & first, const cocos2d::Vec2 & second)
		:GameObject(first, second, spritePath, scene)
	{
		this->scene = scene;
		mouse->onMouseMove = CC_CALLBACK_1(Player::OnMouseMove, this);

	}
	void Player::gameObjectUpdate(float dt)
	{
		if (hitbox->getNode()->getPosition().y > 20.0f)
			hitbox->addForce(cocos2d::Vec2(0, -6.5f), dt);
		else if (hitbox->getNode()->getPosition().y - hitbox->topRight.y <= 20.0f) {
			if (!isEvent(Events::W))
				hitbox->velocity.y = 0.0f;

			hitbox->getNode()->setPosition(hitbox->getNode()->getPosition().x, 20.0f);

		}
		hitbox->update(dt);
		sprite->setPosition(hitbox->getNode()->getPosition() + hitbox->bottomLeft + hitbox->topRight);



		playerUpdate(dt);

	}
	void Player::checkInput(float dt)
	{
		if (isEvent(Events::W))
			hitbox->velocity.y = 5.0f;
		//else if (isEvent(Events::S))
		//	hitbox->addForce(cocos2d::Vec2(0, -10.0f), dt);


		if (isEvent(Events::A))
			hitbox->addForce(cocos2d::Vec2(-10.0f, 0), dt);
		else if (isEvent(Events::D))
			hitbox->addForce(cocos2d::Vec2(10.0f, 0), dt);

		if (!isEvent(Events::A) && !isEvent(Events::D) && hitbox->getNode()->getPosition().y <= 20)
			hitbox->addForce(cocos2d::Vec2(-hitbox->velocity.x * 5, 0), dt);


	}
	void Player::shoot(float dt)
	{
		if (isEvent(Events::Space)) {

			if (shootTimer >= 0.5f) {
				hasShot = false;
				shootTimer = 0;
			}
			if (!hasShot) {
				hasShot = true;
				pProjectiles.push_back(new Projectile(cocos2d::Vec2(0.0f, 0.0f), cocos2d::Vec2(5.0f, 5.0f), scene));
				pProjectiles.back()->getHitbox()->getNode()->setPosition(this->getHitbox()->getNode()->getPosition());


				auto norm = mousePosition / mousePosition.length();
				pProjectiles.back()->getHitbox()->setForce(norm * 500, dt);
				pProjectiles.back()->gameObjectUpdate(dt);
			}
			if (hasShot)
				shootTimer += dt;
		}
	}
	void Player::playerUpdate(float dt)
	{
		checkInput(dt);
		shoot(dt);
	}
	void Player::OnMouseMove(cocos2d::EventMouse * e)
	{
		mousePosition = cocos2d::Vec2(e->getCursorX(), e->getCursorY());
		mousePosition -= cocos2d::Vec2(this->getHitbox()->getNode()->getPosition());

	}
}
