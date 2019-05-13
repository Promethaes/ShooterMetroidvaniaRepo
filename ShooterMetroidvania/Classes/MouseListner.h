#pragma once

#include "cocos2d.h"//including the header instead of forward declaring, due to past issues

namespace Pm{
class MouseListener {
public:
	MouseListener();
	~MouseListener();

	void OnMouseDown(cocos2d::Event* e);
	void OnMouseUp(cocos2d::Event* e);
	void OnMouseMove(cocos2d::Event* e);
	void OnMouseScroll(cocos2d::Event* e);

	cocos2d::EventListenerMouse* getEventListenerMouse() const;

	cocos2d::Label* getLabel() const;
	cocos2d::Vec2 mouseLocation;
private:
	cocos2d::Scene* classScene;
	cocos2d::Label* Label;
	cocos2d::EventListenerMouse* EVENT;
	cocos2d::EventMouse* mouse;
};


}