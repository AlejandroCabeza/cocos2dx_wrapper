#ifndef __ICOMPONENTFACTORY_H__
#define __ICOMPONENTFACTORY_H__

#include "Classes/components/CComponent.h"
#include "Classes/components/AIController.h"
#include "Classes/components/PlayerController.h"
#include "Classes/components/ScreenBorderCollider.h"

class IComponentFactory
{
public:
	virtual ~IComponentFactory() { };

	virtual AIController*         createAIController        (CEntity* parent) const = 0;
	virtual PlayerController*     createPlayerController    (CEntity* parent) const = 0;
	virtual ScreenBorderCollider* createScreenBorderCollider(CEntity* parent) const = 0;

	virtual void removeCComponent(CComponent* component) const = 0;
};

#endif