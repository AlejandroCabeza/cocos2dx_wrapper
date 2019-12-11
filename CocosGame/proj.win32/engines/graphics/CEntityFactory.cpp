#include "CEntityFactory.h"

#include "CSprite.h"

CEntity* CEntityFactory::createEntity(const char * texturePath, float x, float y, CEntity* parent) const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");

	CEntity* entity = SAFE_NEW(CEntity, texturePath, x, y, parent);
	ASSERT_MSG(entity, "Failed to allocate pointer memory.");

	mScene->addChild(static_cast<CSprite*>(entity->getSprite())->getCocosSprite(), 0);
	return entity;
}

CEntity* CEntityFactory::createEntity(std::vector<std::string> tokenizedElement, CEntity* parent) const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");

	CEntity* entity = SAFE_NEW(CEntity, tokenizedElement, parent);
	ASSERT_MSG(entity, "Failed to allocate pointer memory.");

	mScene->addChild(static_cast<CSprite*>(entity->getSprite())->getCocosSprite(), 0);
	return entity;
}

AIEntity* CEntityFactory::createAIEntity(const char* texturePath, float x, float y, CEntity* parent) const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");

	AIEntity* entity = SAFE_NEW(AIEntity, texturePath, x, y, parent);
	ASSERT_MSG(entity, "Failed to allocate pointer memory.");

	mScene->addChild(static_cast<CSprite*>(entity->getSprite())->getCocosSprite(), 0);
	return entity;
}

AIEntity* CEntityFactory::createAIEntity(std::vector<std::string> tokenizedElement, CEntity* parent) const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");

	AIEntity* entity = SAFE_NEW(AIEntity, tokenizedElement, parent);
	ASSERT_MSG(entity, "Failed to allocate pointer memory.");

	mScene->addChild(static_cast<CSprite*>(entity->getSprite())->getCocosSprite(), 0);
	return entity;
}

PlayerEntity* CEntityFactory::createPlayerEntity(const char* texturePath, float x, float y, CEntity* parent) const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");

	PlayerEntity* entity = SAFE_NEW(PlayerEntity, texturePath, x, y, parent);
	ASSERT_MSG(entity, "Failed to allocate pointer memory.");

	mScene->addChild(static_cast<CSprite*>(entity->getSprite())->getCocosSprite(), 0);
	return entity;
}

PlayerEntity* CEntityFactory::createPlayerEntity(std::vector<std::string> tokenizedElement, CEntity* parent) const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");

	PlayerEntity* entity = SAFE_NEW(PlayerEntity, tokenizedElement, parent);
	ASSERT_MSG(entity, "Failed to allocate pointer memory.");

	mScene->addChild(static_cast<CSprite*>(entity->getSprite())->getCocosSprite(), 0);
	return entity;
}

void CEntityFactory::removeCEntity(CEntity* entity) const
{
	SAFE_DELETE(entity);
}

void CEntityFactory::setScene(cocos2d::Scene* scene)
{
	ASSERT_MSG(scene, "Scene not received to switch.");
	mScene = scene;
}
