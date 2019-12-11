#ifndef __CSPRITEFACTORY_H__
#define __CSPRITEFACTORY_H__

#include "ISpriteFactory.h"

#include "Classes/utils/Singleton.h"

class CSpriteFactory : public ISpriteFactory, public Singleton<CSpriteFactory>
{
public:
	virtual ISprite* createSpriteFromSpriteFrame     (const char* texturePath) const override;
	virtual ISprite* createSpriteFromSpriteFrameCache(const char* texturePath) const override;
};

#endif