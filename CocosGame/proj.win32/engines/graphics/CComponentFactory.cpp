#include "CComponentFactory.h"

AIController* CComponentFactory::createAIController(CEntity* parent) const
{
	ASSERT_MSG(parent, "Parent not defined to link the component to.");

	AIController* component = SAFE_NEW(AIController, parent);
	ASSERT_MSG(component, "Failed to allocate pointer memory.");

	parent->addComponent(component);
	return component;
}

PlayerController* CComponentFactory::createPlayerController(CEntity* parent) const
{
	ASSERT_MSG(parent, "Parent not defined to link the component to.");

	PlayerController* component = SAFE_NEW(PlayerController, parent);
	ASSERT_MSG(component, "Failed to allocate pointer memory.");

	parent->addComponent(component);
	return component;
}

ScreenBorderCollider* CComponentFactory::createScreenBorderCollider(CEntity* parent) const
{
	ASSERT_MSG(parent, "Parent not defined to link the component to.");

	ScreenBorderCollider* component = SAFE_NEW(ScreenBorderCollider, parent);
	ASSERT_MSG(component, "Failed to allocate pointer memory.");

	parent->addComponent(component);
	return component;
}

void CComponentFactory::removeCComponent(CComponent* component) const
{
	SAFE_DELETE(component);
}
