#ifndef __PLAYERCONTROLLER_H__
#define __PLAYERCONTROLLER_H__

#include "CComponent.h"
#include "proj.win32/engines/input/IInputManager.h"

class PlayerController : public CComponent
{
private:
	float mSpeed;

	void move(float deltaTime) const;
	void callbackInputManager(IInputManager::EventType eventType, int x, int y);

public:
	PlayerController(CEntity* parent);

	virtual bool init  ()                override;
	virtual void update(float deltaTime) override;
};

#endif