#ifndef __CINPUTMANAGER_CPP__
#define __CINPUTMANAGER_CPP__

#include "CInputManager.h"

#include "Globals.h"

CInputManager::CInputManager(cocos2d::Scene* scene)
{
	ASSERT_MSG(scene, "CInputManager didn't receive scene to attach.");

	mIdGenerator   = 0;
	mScene         = scene;
	mTouchListener = nullptr;
}

CInputManager::~CInputManager()
{
	mTouchListener = nullptr;
	mScene         = nullptr;	
}

bool CInputManager::init()
{
	mTouchListener = cocos2d::EventListenerTouchOneByOne::create();
	mTouchListener->setSwallowTouches(true);

	mTouchListener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		cocos2d::Vec2 location = touch->getLocation();
		
		for (auto it = mVectorTouchListeners.begin(); it != mVectorTouchListeners.end(); ++it)
		{
			it->mFunc(EventType::TouchDown, location.x, location.y);
		}

		return true;
	};

	mTouchListener->onTouchMoved = [this](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		cocos2d::Vec2 location = touch->getLocation();
		
		for (auto it = mVectorTouchListeners.begin(); it != mVectorTouchListeners.end(); ++it)
		{
			it->mFunc(EventType::TouchMove, location.x, location.y);
		}

		return true;
	};

	mTouchListener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		cocos2d::Vec2 location = touch->getLocation();
		
		for (auto it = mVectorTouchListeners.begin(); it != mVectorTouchListeners.end(); ++it)
		{
			it->mFunc(EventType::TouchUp, location.x, location.y);
		}

		return true;
	};

	if (mScene)
		cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mTouchListener, mScene);
	else 
		cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority     (mTouchListener, 1);

	return true;
}

unsigned int CInputManager::subscribeToTouchEvents(std::function<void(EventType, int x, int y)> func)
{
	ASSERT_MSG(func, "Can't subscribe with empty function.");

	unsigned int index = mIdGenerator;
	mVectorTouchListeners.push_back(TouchListener(mIdGenerator++, func));
	return index;
}

void CInputManager::removeFromTouchEvents(unsigned int id)
{
	for (auto it = mVectorTouchListeners.begin(); it != mVectorTouchListeners.end(); ++it)
	{
		if (it->mId == id) mVectorTouchListeners.erase(it);
	}
}

#endif
