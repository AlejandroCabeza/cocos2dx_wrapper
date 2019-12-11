#ifndef __SCREENBORDERCOLLIDER_H__
#define __SCREENBORDERCOLLIDER_H__

#include "CComponent.h"

class ScreenBorderCollider : public CComponent
{
private: 
	void checkBorderCollision() const;

public:
	ScreenBorderCollider(CEntity* parent);

	virtual bool init  ()                override;
	virtual void update(float deltaTime) override;
};

#endif