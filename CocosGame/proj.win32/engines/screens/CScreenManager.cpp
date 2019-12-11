#include "CScreenManager.h"

#include <fstream>

#include "Classes/scenes/MainScreen.h"

#include "Globals.h"
#include "cocos2d.h"


CScreenManager::CScreenManager()
{
	mScreen = nullptr;
}

CScreenManager::~CScreenManager()
{
	removeGameScreen();
}

void CScreenManager::createGameMainScreen()
{
	mScreen = SAFE_NEW(MainScreen);
	mScreen->init();

	cocos2d::Director::getInstance()->getScheduler()->scheduleUpdate(mScreen, 0, false);
}

void CScreenManager::removeGameScreen()
{
	if (mScreen)
	{
		cocos2d::Director::getInstance()->getScheduler()->unscheduleUpdate(mScreen);
		SAFE_DELETE(mScreen);
	}
}

void CScreenManager::createGameScreenFromFile(const char* screenPath)
{
	ASSERT_MSG(screenPath,       "Screen path is null pointer.");
	ASSERT_MSG(screenPath != "", "Screen path is empty.");

	std::ifstream sceneFile(screenPath);
	ASSERT_MSG(sceneFile.is_open(), "Screen path doesn't link to any file.");

	std::string line = "";
	std::vector<std::string> screenElements;
	
	while (std::getline(sceneFile, line, '\n'))
	{
		screenElements.push_back(line);
	}

	ASSERT_MSG(screenElements.size() > 0, "Screen path doesn't link to any file.");

	mScreen = SAFE_NEW(CScreen, screenElements);
	mScreen->init();

	cocos2d::Director::getInstance()->getScheduler()->scheduleUpdate(mScreen, 0, false);
}
