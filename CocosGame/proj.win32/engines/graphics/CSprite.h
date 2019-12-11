#ifndef __CSPRITE_H__
#define __CSPRITE_H__

#include "ISprite.h"
#include "cocos2d.h"

class CSprite : public ISprite
{
private:
	cocos2d::Sprite* mSprite;

public:
	CSprite(const char* texturePath);
	virtual ~CSprite();

	void setTexture (const char* texturePath)                 override;
	void setPosition(float x, float y) override;
	void setScale   (float x, float y) override;
	void setRotation(float x, float y) override;
	void setAlpha   (byte alpha)      override;

	Vector2D getScale   () const override;
	Vector2D getPosition() const override;
	Vector2D getSize    () const override;
	float    getRotation() const override;
	byte     getAlpha   () const override;

	cocos2d::Sprite* getCocosSprite() const;

	void addChildSprite   (ISprite* sprite, int zOrder, float x, float y) const override;
	void removeChildSprite(ISprite* sprite)                               const override;
};

#endif
