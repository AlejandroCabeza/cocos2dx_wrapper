#include "AIController.h"

#include "proj.win32/engines/manager/CManager.h"

AIController::AIController(CEntity* parent) : CComponent(parent)
{
	mSpeed = 50;
	mIsMovingRight = true;
}

bool AIController::init()
{
	return true;
}

void AIController::update(float deltaTime)
{
	move(deltaTime);
	checkScreenBorders();
}

void AIController::move(float deltaTime) const
{
	if (mIsMovingRight)
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

void AIController::checkScreenBorders()
{
	Vector2D screenOrigin = CManager::getInstance()->getGraphicsModule()->getScreenVisibleOrigin();
	Vector2D screenSize   = CManager::getInstance()->getGraphicsModule()->getScreenVisibleSize();

	int posX      = mParent->getSprite()->getPosition().getX();
	int sizeXHalf = mParent->getSprite()->getSize()    .getX() / 2;

	if     ((screenOrigin.getX() + screenSize.getX()) < (posX + sizeXHalf))
	{
		mIsMovingRight = false;
	}
	else if (screenOrigin.getX()                      > (posX - sizeXHalf))
	{
		mIsMovingRight = true;
	}
}
