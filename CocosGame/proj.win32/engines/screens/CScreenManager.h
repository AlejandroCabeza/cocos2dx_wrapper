#ifndef __CSCREENMANAGER_H__
#define __CSCREENMANAGER_H__

#include "IScreenManager.h"

#include "Classes/scenes/MainScreen.h"

class CScreenManager : public IScreenManager
{
private:
	CScreen* mScreen;

public:
	CScreenManager();
	virtual ~CScreenManager();

	virtual void createGameMainScreen() override;
	virtual void removeGameScreen() override;

	virtual void createGameScreenFromFile(const char* screenPath) override;
};

#endif