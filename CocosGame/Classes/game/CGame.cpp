#include "CGame.h"

CGame::CGame()
{
	mManager = CManager::getInstance();
}

CGame::~CGame()
{
	if (mManager)
	{
		SAFE_DELETE(mManager);
	}
}

bool CGame::init() const
{
	mManager->init();
	
	mManager->getScreenManager()->createGameScreenFromFile("res/screens/MainScreenTokenized.txt");

	return true;
}