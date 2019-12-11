#ifndef __CCOMPONENTFACTORY_H__
#define __CCOMPONENTFACTORY_H__

#include "IComponentFactory.h"

#include "Classes/utils/Singleton.h"
#include "cocos2d.h"

class CComponentFactory : public IComponentFactory, public Singleton<CComponentFactory>
{
public:
	virtual ~CComponentFactory() { };

	virtual AIController*         createAIController        (CEntity* parent) const override;
	virtual PlayerController*     createPlayerController    (CEntity* parent) const override;
	virtual ScreenBorderCollider* createScreenBorderCollider(CEntity* parent) const override;

	virtual void removeCComponent(CComponent* component) const override;
};

#endif
