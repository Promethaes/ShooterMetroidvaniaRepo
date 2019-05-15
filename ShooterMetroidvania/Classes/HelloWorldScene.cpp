/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <iostream>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	testPlayer = new Sedna::Player("HelloWorld.png", this);
	testPlayer->getHitbox()->bottomLeft += cocos2d::Vec2(80, 80);
	testPlayer->getHitbox()->topRight += cocos2d::Vec2(80, 80);

	this->addChild(background, -100);
	ground = new Sedna::Hitbox(cocos2d::Vec2(0, 0), cocos2d::Vec2(10000, 40), this);

	this->getEventDispatcher()->addEventListenerWithFixedPriority(testPlayer->mouse, 10);


	this->scheduleUpdate();
	return true;
}

void HelloWorld::update(float dt)
{


	for (int i = 0; i < Sedna::GameObject::gameObjects.size(); i++) {
		Sedna::GameObject::gameObjects[i]->gameObjectUpdate(dt);

		for (int j = 0; j < Sedna::GameObject::gameObjects.size(); j++) {
			if (i == j)
				continue;
			if (Sedna::GameObject::gameObjects[i]->getHitbox()->checkCollision(*Sedna::GameObject::gameObjects[j]->getHitbox())) {

				//Sedna::GameObject::gameObjects[i]->getHitbox()->velocity -= Sedna::GameObject::gameObjects[i]->getHitbox()->velocity;
				//Sedna::GameObject::gameObjects[j]->getHitbox()->velocity -= Sedna::GameObject::gameObjects[i]->getHitbox()->velocity;

			}
		}

		if (Sedna::GameObject::gameObjects[i]->getHitbox()->checkCollision(*ground)) {
			if (Sedna::GameObject::gameObjects[i]->id == 2 && !isEvent(Events::W)) {
				Sedna::GameObject::gameObjects[i]->getHitbox()->velocity.y = 0;

				///<HELP ME I CANT FIX THIS AHHH>
				Sedna::GameObject::gameObjects[i]->getHitbox()->bottomLeft.y++;
				Sedna::GameObject::gameObjects[i]->getHitbox()->topRight.y++;


			}

			else if (Sedna::GameObject::gameObjects[i]->id == 1) {
				Sedna::GameObject::gameObjects[i]->getHitbox()->velocity.y = 0;
				///<HELP ME I CANT FIX THIS AHHH>
				Sedna::GameObject::gameObjects[i]->getHitbox()->bottomLeft.y++;
				Sedna::GameObject::gameObjects[i]->getHitbox()->topRight.y++;

			}


		}
	}

	//if (testPlayer->getHitbox()->checkCollision(*ground)) {
	//	testPlayer->getHitbox()->velocity *= -1;
	//}

}




