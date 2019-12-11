#ifndef __CENTITY_H__
#define __CENTITY_H__

#include "Classes/components/CComponent.h"

#include "proj.win32/engines/graphics/ISprite.h"
#include "proj.win32/engines/input/IInputManager.h"

#include <vector>

class CComponent;

class CEntity
{
protected:
	unsigned int             mListenerId;
	IInputManager::EventType mEventType;
	int                      mEventX;
	int                      mEventY;

	CEntity*                 mParent;
	ISprite*                 mSprite;
	std::vector<CEntity*>    mEntities;
	std::vector<CComponent*> mComponents;

public:
	CEntity(const char* texturePath, float x, float y, CEntity* parent);
	CEntity(std::vector<std::string> tokenizedElement, CEntity* parent);
	virtual ~CEntity();

	virtual bool init();
	virtual void update(float deltaTime);

	void addEntity(CEntity* entity);
	void addComponent(CComponent* component);

	ISprite* getSprite() const;
};

#endif