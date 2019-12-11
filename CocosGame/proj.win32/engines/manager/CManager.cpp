#include "CManager.h"

#include "proj.win32/engines/graphics/CGraphics.h"
#include "proj.win32/engines/input/CInputManager.h"
#include "proj.win32/engines/screens/CScreenManager.h"

#include "Globals.h"

CManager::CManager()
{
	mGraphics      = nullptr;
	mInputManager  = nullptr;
	mScreenManager = nullptr;
}

CManager::~CManager()
{
	if (mScreenManager) SAFE_DELETE(mScreenManager);
	if (mGraphics)      SAFE_DELETE(mGraphics);
	if (mInputManager)  SAFE_DELETE(mInputManager);
}

bool CManager::init()
{
	cocos2d::Scene* scene = nullptr;

	if (!mGraphics)
	{
		mGraphics = SAFE_NEW(CGraphics);
		ASSERT_MSG(mGraphics, "Failed to initialise Graphics module.");

		mGraphics->createScene();

		scene = static_cast<CGraphics*>(mGraphics)->getScene();
		ASSERT_MSG(scene, "Scene not correctly gotten.");
	}

	if (!mInputManager || !scene)
	{
		mInputManager = SAFE_NEW(CInputManager, scene);
		ASSERT_MSG(mInputManager, "Failed to initialise Input module.");

		mInputManager->init();
	}

	if (!mScreenManager)
	{
		mScreenManager = SAFE_NEW(CScreenManager);
		ASSERT_MSG(mScreenManager, "Failed to initialise Screen module.");
	}

	return true;
}

IGraphics* CManager::getGraphicsModule() const
{
	ASSERT_MSG(mGraphics, "Graphics module not initialised.");
	return mGraphics;
}

IInputManager* CManager::getInputManager() const
{
	ASSERT_MSG(mGraphics, "Input module not initialised.");
	return mInputManager;
}

CScreenManager* CManager::getScreenManager() const
{
	ASSERT_MSG(mScreenManager, "Input module not initialised.");
	return mScreenManager;
}
