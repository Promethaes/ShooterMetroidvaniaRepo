#include "MouseListner.h"

Pm::MouseListener::MouseListener() 
{

	MouseListener::EVENT = cocos2d::EventListenerMouse::create();
	
	
	Label = cocos2d::Label::create("Hello","Resources/fonts/arial.ttf",12);
	Label->setPosition(cocos2d::Vec2(200, 200));
	//Label->setVisible(true);

	EVENT->onMouseDown = CC_CALLBACK_1(Pm::MouseListener::OnMouseDown, this);
	EVENT->onMouseUp = CC_CALLBACK_1(Pm::MouseListener::OnMouseUp, this);
	EVENT->onMouseMove = CC_CALLBACK_1(Pm::MouseListener::OnMouseMove, this);
	EVENT->onMouseScroll = CC_CALLBACK_1(Pm::MouseListener::OnMouseScroll, this);
}

Pm::MouseListener::~MouseListener()
{
	delete EVENT;
	delete Label;
}

void Pm::MouseListener::OnMouseDown(cocos2d::Event * e)
{
	//Label->setString("Mouse Clicked!11!1!!");
}

void Pm::MouseListener::OnMouseUp(cocos2d::Event * e)
{
	//Label->setString("Mouse Up!11!1!!");

}

void Pm::MouseListener::OnMouseMove(cocos2d::Event* e)
{
	
	//Label->setString("Mouse Moved!11!1!!");

}

void Pm::MouseListener::OnMouseScroll(cocos2d::Event * e)
{
	//Label->setString("Mouse Scrolled!11!1!!");

}

cocos2d::EventListenerMouse * Pm::MouseListener::getEventListenerMouse() const
{
	return EVENT;
}

cocos2d::Label * Pm::MouseListener::getLabel() const
{
	return Label;
}
