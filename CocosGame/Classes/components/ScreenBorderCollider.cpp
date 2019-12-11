#include "ScreenBorderCollider.h"

#include "proj.win32/engines/manager/CManager.h"

void ScreenBorderCollider::checkBorderCollision() const
{
	Vector2D screenOrigin = CManager::getInstance()->getGraphicsModule()->getScreenVisibleOrigin();
	Vector2D screenSize   = CManager::getInstance()->getGraphicsModule()->getScreenVisibleSize();

	auto sprite = mParent->getSprite();

	int posX      = sprite->getPosition().getX();
	int sizeXHalf = sprite->getSize()    .getX() / 2;

	if     ((screenOrigin.getX() + screenSize.getX()) < (posX + sizeXHalf))
	{
		sprite->setPosition(
			screenOrigin.getX() + screenSize.getX() - sizeXHalf,
			sprite->getPosition().getY());
	}
	else if (screenOrigin.getX()                      > (posX - sizeXHalf))
	{
		sprite->setPosition(
			screenOrigin.getX() + sizeXHalf,
			sprite->getPosition().getY());
	}
}

ScreenBorderCollider::ScreenBorderCollider(CEntity* parent) : CComponent(parent)
{

}

bool ScreenBorderCollider::init()
{
	return true;
}

void ScreenBorderCollider::update(float deltaTime)
{
	checkBorderCollision();
}
