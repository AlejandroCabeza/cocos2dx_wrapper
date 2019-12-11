#include "PlayerController.h"

#include "proj.win32/engines/manager/CManager.h"

PlayerController::PlayerController(CEntity* parent) : CComponent(parent)
{
	mSpeed = 150;
}

bool PlayerController::init()
{
	mListenerId = CManager::getInstance()->getInputManager()->subscribeToTouchEvents(std::bind(&PlayerController::callbackInputManager, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	return true;
}

void PlayerController::update(float deltaTime)
{
	move(deltaTime);
}

void PlayerController::move(float deltaTime) const
{
	if (mEventType == IInputManager::TouchDown || mEventType == IInputManager::TouchMove)
	{
		int previousX = mParent->getSprite()->getPosition().getX();

		if (previousX < mEventX)
		{
			mParent->getSprite()->setPosition(
				mParent->getSprite()->getPosition().getX() + (mSpeed * deltaTime),
				mParent->getSprite()->getPosition().getY());
		}
		else
		{
			mParent->getSprite()->setPosition(
				mParent->getSprite()->getPosition().getX() - (mSpeed * deltaTime),
				mParent->getSprite()->getPosition().getY());
		}
	}
}

void PlayerController::callbackInputManager(IInputManager::EventType eventType, int x, int y)
{
	ASSERT_MSG(eventType != IInputManager::None, "Event type not expected.");

	mEventType = eventType;
	mEventX    = x;
	mEventY    = y;
}
