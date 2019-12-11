#include "CSreen.h"

#include "proj.win32/engines/manager/CManager.h"
#include <Windows.h>

#include "Classes/utils/StringUtils.h"

CScreen::CScreen()
{
	mGraphics = CManager::getInstance()->getGraphicsModule();
}

CScreen::CScreen(std::vector<std::string> screenElements) : CScreen()
{
	for (std::string element : screenElements)
	{

		std::vector<std::string> tokenizedElement = StringUtils::tokenizeString(element.c_str(), ' ');
		std::string id = tokenizedElement[0];
		
		if      (id == "CE")
		{
			unsigned int parent = atoi(tokenizedElement[4].c_str());

			ASSERT_MSG(parent < mEntities.size() || -1, "Parent ID for entity could not be found");
			
			CEntity* entity = mGraphics->getEntityFactory()->createEntity(tokenizedElement,
				parent == -1 ? nullptr : mEntities[parent]);

			mEntities.push_back(entity);
		}
		else if (id == "AIE")
		{
			std::string path    =      tokenizedElement[1];
			unsigned int parent = atoi(tokenizedElement[4].c_str());

			ASSERT_MSG(parent < mEntities.size() || -1, "Parent ID for entity could not be found");

			AIEntity* entity = mGraphics->getEntityFactory()->createAIEntity(tokenizedElement,
				parent == -1 ? nullptr : mEntities[parent]);

			mEntities.push_back(entity);
		}
		else if (id == "PE")
		{
			std::string path    =      tokenizedElement[1];
			unsigned int parent = atoi(tokenizedElement[4].c_str());

			ASSERT_MSG(parent < mEntities.size() || -1, "Parent ID for entity could not be found");

			PlayerEntity* entity = mGraphics->getEntityFactory()->createPlayerEntity(tokenizedElement,
				parent == -1 ? nullptr : mEntities[parent]);

			mEntities.push_back(entity);
		}
		else if (id == "AIC")
		{
			unsigned int parent = atoi(tokenizedElement[1].c_str());

			ASSERT_MSG(parent < mEntities.size(), "Parent ID for component could not be found");

			AIController* component = mGraphics->getComponentFactory()->createAIController(mEntities[parent]);
		}
		else if (id == "PCC")
		{
			unsigned int parent = atoi(tokenizedElement[1].c_str());

			ASSERT_MSG(parent < mEntities.size(), "Parent ID for component could not be found");

			PlayerController* component = mGraphics->getComponentFactory()->createPlayerController(mEntities[parent]);
		}
		else if (id == "SBCC")
		{
			unsigned int parent = atoi(tokenizedElement[1].c_str());

			ASSERT_MSG(parent < mEntities.size(), "Parent ID for component could not be found");

			ScreenBorderCollider* component = mGraphics->getComponentFactory()->createScreenBorderCollider(mEntities[parent]);
		}
		else if (id == "Exit")
		{
			mGraphics->drawExitButton();
		}
	}
}

CScreen::~CScreen()
{
	for (auto entity : mEntities) mGraphics->getEntityFactory()->removeCEntity(entity);
}

bool CScreen::init()
{
	for (auto entity : mEntities) entity->init();
	return true;
}

void CScreen::update(float deltaTime)
{
	for (auto entity : mEntities) entity->update(deltaTime);
}

void CScreen::addEntity(CEntity * entity)
{
	mEntities.push_back(entity);
}
