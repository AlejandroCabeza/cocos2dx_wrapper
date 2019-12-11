#include "CSpriteFactory.h"

#include "CSprite.h"

ISprite* CSpriteFactory::createSpriteFromSpriteFrame(const char* texturePath) const
{
	ASSERT_MSG(texturePath,       "Texture path is null pointer.");
	ASSERT_MSG(texturePath != "", "Texture path is empty.");

	ISprite* sprite = SAFE_NEW(CSprite, texturePath);
	ASSERT_MSG(sprite, "Failed to allocate pointer memory.");
	return sprite;
}

ISprite* CSpriteFactory::createSpriteFromSpriteFrameCache(const char* texturePath) const
{
	ASSERT_MSG(texturePath,       "Texture path is null pointer.");
	ASSERT_MSG(texturePath != "", "Texture path is empty.");

	return nullptr;
}