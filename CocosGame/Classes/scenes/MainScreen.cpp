#include "MainScreen.h"

#include "proj.win32/engines/manager/CManager.h"
#include "proj.win32/engines/graphics/CSprite.h"

#include "../entities/PlayerEntity.h"
#include "../entities/AIEntity.h"

USING_NS_CC;

MainScreen::MainScreen() : CScreen()
{
	mGraphics->drawExitButton();

	PlayerEntity* playerEntity = mGraphics->getEntityFactory()->createPlayerEntity("res/spaceships/ship1.png",
		mGraphics->getScreenVisibleSize().getX() / 2 + mGraphics->getScreenVisibleOrigin().getX(),
		mGraphics->getScreenVisibleOrigin().getY(),
		nullptr);

	playerEntity->getSprite()->setPosition(
		playerEntity->getSprite()->getPosition().getX(),
		playerEntity->getSprite()->getPosition().getY() + playerEntity->getSprite()->getSize().getY() / 2);

	mEntities.push_back(playerEntity);


	AIEntity* aiEntity = mGraphics->getEntityFactory()->createAIEntity("res/spaceships/ship2.png",
		mGraphics->getScreenVisibleSize().getX() / 2 + mGraphics->getScreenVisibleOrigin().getX(),
		mGraphics->getScreenVisibleOrigin().getY() + mGraphics->getScreenVisibleSize().getY(),
		nullptr);

	aiEntity->getSprite()->setPosition(aiEntity->getSprite()->getPosition().getX(),
		aiEntity->getSprite()->getPosition().getY() - aiEntity->getSprite()->getSize().getY() / 2);

	mEntities.push_back(aiEntity);
}

MainScreen::~MainScreen()
{
	
}

bool MainScreen::init()
{
	





	return CScreen::init();
}

void MainScreen::update(float deltaTime)
{
	CScreen::update(deltaTime);
}
