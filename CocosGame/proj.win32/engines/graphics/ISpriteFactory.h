#ifndef __ISPRITEFACTORY__H_
#define __ISPRITEFACTORY__H_

#include "ISprite.h"

class ISpriteFactory
{
public:
	virtual ~ISpriteFactory() { };

	virtual ISprite* createSpriteFromSpriteFrame     (const char* texturePath) const = 0;
	virtual ISprite* createSpriteFromSpriteFrameCache(const char* texturePath) const = 0;
};

#endif