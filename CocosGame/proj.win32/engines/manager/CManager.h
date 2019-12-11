#ifndef __CMANAGER_H__
#define __CMANAGER_H__

#include "Classes/utils/Singleton.h"

#include "proj.win32/engines/graphics/IGraphics.h"
#include "proj.win32/engines/input/IInputManager.h"
#include "proj.win32/engines/screens/IScreenManager.h"
#include "proj.win32/engines/screens/CScreenManager.h"

class CManager : public Singleton<CManager>
{
private:
	IGraphics*      mGraphics;
	IInputManager*  mInputManager;
	CScreenManager* mScreenManager;

public:
	CManager();
	~CManager();

	bool init();

	IGraphics*      getGraphicsModule() const;
	IInputManager*  getInputManager  () const;
	CScreenManager* getScreenManager () const;
};

#endif
