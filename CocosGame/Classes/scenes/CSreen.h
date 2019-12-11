#ifndef __CSCREEN_H__
#define __CSCREEN_H__

#include "Classes/entities/CEntity.h"
#include "proj.win32/engines/graphics/IGraphics.h"

class CScreen
{
protected:
	IGraphics* mGraphics;

	std::vector<CEntity*> mEntities;

public:
	CScreen();
	CScreen(std::vector<std::string> screenElements);
	virtual ~CScreen();

	virtual bool init();
	virtual void update(float deltaTime);

	void addEntity(CEntity* entity);
};

#endif