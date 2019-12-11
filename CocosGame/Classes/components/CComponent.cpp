#include "CComponent.h"
#include "Globals.h"

CComponent::CComponent(CEntity* parent)
{
	ASSERT_MSG(parent, "Parent entity is a null pointer.");

	mParent     = parent;

	mListenerId = -1;
	mEventType  = IInputManager::None;
	mEventX     = 0;
	mEventY     = 0;
}
