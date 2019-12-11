#include "PlayerEntity.h"

#include "proj.win32/engines/manager/CManager.h"
#include "proj.win32/engines/graphics/CSprite.h"
#include "Classes/components/PlayerController.h"
#include "Classes/components/ScreenBorderCollider.h"

#include "Globals.h"

PlayerEntity::PlayerEntity(const char* texturePath, float x, float y, CEntity* parent) : CEntity(texturePath, x, y, parent)
{

}

PlayerEntity::PlayerEntity(std::vector<std::string> tokenizedElement, CEntity * parent) : CEntity(tokenizedElement, parent)
{
}

bool PlayerEntity::init()
{
	CManager::getInstance()->getGraphicsModule()->getComponentFactory()->createPlayerController    (this);
	CManager::getInstance()->getGraphicsModule()->getComponentFactory()->createScreenBorderCollider(this);

	CEntity::init();

	return true;
}

void PlayerEntity::update(float deltaTime)
{
	CEntity::update(deltaTime);
}

