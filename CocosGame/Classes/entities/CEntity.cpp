#include "CEntity.h"

#include "proj.win32/engines/graphics/CSprite.h"
#include "proj.win32/engines/manager/CManager.h"

#include "Globals.h"


CEntity::CEntity(const char* texturePath, float x, float y, CEntity* parent)
{
	ASSERT_MSG(texturePath,       "Texture path is null pointer.");
	ASSERT_MSG(texturePath != "", "Texture path is empty.");

	mParent = parent;
	mSprite = CManager::getInstance()->getGraphicsModule()->getSpriteFactory()->createSpriteFromSpriteFrame(texturePath);
	mSprite->setPosition(x, y);

	mListenerId = 0;
	mEventType = IInputManager::None;
	mEventX = 0;
	mEventY = 0;
}

CEntity::CEntity(std::vector<std::string> tokenizedElement, CEntity * parent) :
	CEntity(tokenizedElement[1].c_str(), float(atof(tokenizedElement[2].c_str())), float(atof(tokenizedElement[3].c_str())), parent)
{

}

CEntity::~CEntity()
{
	                                   SAFE_DELETE(mSprite);
	for (auto entity    : mEntities)   CManager::getInstance()->getGraphicsModule()->getEntityFactory()   ->removeCEntity   (entity);
	for (auto component : mComponents) CManager::getInstance()->getGraphicsModule()->getComponentFactory()->removeCComponent(component);
}

bool CEntity::init()
{
	for (auto entity    : mEntities)   entity   ->init();
	for (auto component : mComponents) component->init();

	return true;
}

void CEntity::update(float deltaTime)
{
	for (auto entity    : mEntities)   entity   ->update(deltaTime);
	for (auto component : mComponents) component->update(deltaTime);
}

void CEntity::addEntity(CEntity* entity)
{
	mEntities.push_back(entity);
}

void CEntity::addComponent(CComponent * component)
{
	mComponents.push_back(component);
}

ISprite* CEntity::getSprite() const
{
	return mSprite;
}
