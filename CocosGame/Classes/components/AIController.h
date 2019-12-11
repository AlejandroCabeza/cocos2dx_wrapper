#ifndef __AICONTROLLER_H__
#define __AICONTROLLER_H__

#include "CComponent.h"

class CEntity;

class AIController : public CComponent
{
private:
	float mSpeed;
	bool  mIsMovingRight;

	void move(float deltaTime) const;
	void checkScreenBorders();

public:
	AIController(CEntity* parent);

	virtual bool init  ()                override;
	virtual void update(float deltaTime) override;
};

#endif
