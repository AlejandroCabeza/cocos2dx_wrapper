#ifndef __CCOMPONENT_H__
#define __CCOMPONENT_H__

#include "Classes/entities/CEntity.h"
#include "proj.win32/engines/input/IInputManager.h"

class CEntity;

class CComponent
{
protected:
	unsigned int             mListenerId;
	IInputManager::EventType mEventType;
	int                      mEventX;
	int                      mEventY;

	CEntity*                 mParent;

public:
	CComponent(CEntity* parent);
	virtual ~CComponent() { };

	virtual bool init  ()                = 0;
	virtual void update(float deltaTime) = 0;
};

#endif