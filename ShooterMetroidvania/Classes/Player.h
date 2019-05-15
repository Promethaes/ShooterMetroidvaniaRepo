#pragma once
#include "GameObject.h"
#include "Input.h"
#include "Events.h"
#include "Projectile.h"

namespace Sedna {
	class Player : public GameObject {
	public:
		Player(const std::string spritePath, cocos2d::Scene* scene, const cocos2d::Vec2& first = cocos2d::Vec2(70.0f, 80.0f), const cocos2d::Vec2& second = cocos2d::Vec2(110.0f, 120.0f));

		void gameObjectUpdate(float dt) override;
		void checkInput(float dt);
		void shoot(float dt);
		void playerUpdate(float dt);
		void OnMouseMove(cocos2d::EventMouse* e);

		std::vector<Projectile*> getProjectiles() const { return pProjectiles; }

		cocos2d::EventListenerMouse* mouse = cocos2d::EventListenerMouse::create();
	private:
		std::vector<Projectile*> pProjectiles;
		float shootTimer = 0;
		bool hasShot = false;
		cocos2d::Scene* scene;
		cocos2d::Vec2 mousePosition;

	};

	
}

