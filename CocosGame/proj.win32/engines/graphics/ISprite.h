#ifndef __ISPRITE__H_
#define __ISPRITE__H_

#include "Classes/Utils/Vector2D.h"
#include "IPaint.h"

class ISprite
{
public:
	virtual ~ISprite() { };

	virtual void setTexture (const char* texturePath) = 0;
	virtual void setPosition(float x, float y)        = 0;
	virtual void setScale   (float x, float y)        = 0;
	virtual void setRotation(float x, float y)        = 0;
	virtual void setAlpha   (byte alpha)              = 0;

	virtual Vector2D getScale   () const = 0;
	virtual Vector2D getPosition() const = 0;
	virtual Vector2D getSize    () const = 0;
	virtual float    getRotation() const = 0;
	virtual byte     getAlpha   () const = 0;

	virtual void addChildSprite   (ISprite* sprite, int zOrder, float x, float y) const = 0;
	virtual void removeChildSprite(ISprite* sprite)                               const = 0;
};

#endif