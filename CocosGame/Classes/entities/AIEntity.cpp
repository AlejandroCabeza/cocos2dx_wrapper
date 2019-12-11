#include "AIEntity.h"

#include "proj.win32/engines/manager/CManager.h"
#include "proj.win32/engines/graphics/CSprite.h"
#include "Classes/components/AIController.h"
#include "Classes/components/ScreenBorderCollider.h"

#include "Globals.h"

AIEntity::AIEntity(const char* texturePath, float x, float y, CEntity* parent) : CEntity(texturePath, x, y, parent)
{

}

AIEntity::AIEntity(std::vector<std::string> tokenizedElement, CEntity * parent) : CEntity(tokenizedElement, parent)
{
}

bool AIEntity::init()
{
	CManager::getInstance()->getGraphicsModule()->getComponentFactory()->createAIController        (this);
	CManager::getInstance()->getGraphicsModule()->getComponentFactory()->createScreenBorderCollider(this);

	CEntity::init();

	return true;
}

void AIEntity::update(float deltaTime)
{
	CEntity::update(deltaTime);
}