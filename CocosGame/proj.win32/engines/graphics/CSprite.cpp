#include "CSprite.h"
#include "Globals.h"

CSprite::CSprite(const char* texturePath)
{
	ASSERT_MSG(texturePath,       "Texture path is null pointer.");
	ASSERT_MSG(texturePath != "", "Texture path is empty.");

	mSprite = cocos2d::Sprite::create(texturePath);
	mSprite->retain();
}

CSprite::~CSprite()
{
	mSprite->release();
}

void CSprite::setTexture(const char* texturePath)
{
	ASSERT_MSG(texturePath,       "Texture path is null pointer.");
	ASSERT_MSG(texturePath != "", "Texture path is empty.");

	mSprite->setTexture(texturePath);
}

void CSprite::setPosition(float x, float y)
{
	mSprite->setPosition(x, y);
}

void CSprite::setScale(float x, float y)
{
	mSprite->setScale(x, y);
}

void CSprite::setRotation(float x, float y)
{
	mSprite->setRotationSkewX(x);
	mSprite->setRotationSkewY(y);
}

void CSprite::setAlpha(byte alpha)
{
	mSprite->setOpacity(alpha);
}

Vector2D CSprite::getScale() const
{
	return Vector2D(mSprite->getScaleX(), mSprite->getScaleY());
}

Vector2D CSprite::getPosition() const
{
	return Vector2D(mSprite->getPosition().x, mSprite->getPosition().y);
}

Vector2D CSprite::getSize() const
{
	return Vector2D(mSprite->getContentSize().width, mSprite->getContentSize().height);
}

float CSprite::getRotation() const
{
	return mSprite->getRotation();
}

byte CSprite::getAlpha() const
{
	return mSprite->getOpacity();
}

cocos2d::Sprite* CSprite::getCocosSprite() const
{
	return mSprite;
}

void CSprite::addChildSprite(ISprite* sprite, int zOrder, float x, float y) const
{
	ASSERT_MSG(sprite, "Child sprite is null pointer.");

	sprite->setPosition(x, y);
	mSprite->addChild(static_cast<CSprite*>(sprite)->getCocosSprite(), zOrder);
}

void CSprite::removeChildSprite(ISprite* sprite) const
{
	ASSERT_MSG(sprite, "Child sprite is null pointer.");

	mSprite->removeChild(static_cast<CSprite*>(sprite)->getCocosSprite(), true);
}