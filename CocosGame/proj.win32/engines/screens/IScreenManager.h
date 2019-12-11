#ifndef __ISCREENMANAGER_H__
#define __ISCREENMANAGER_H__

class IScreenManager
{
public:
	virtual ~IScreenManager() { };

	virtual void createGameMainScreen() = 0;
	virtual void removeGameScreen() = 0;

	virtual void createGameScreenFromFile(const char* screenPath) = 0;
};

#endif