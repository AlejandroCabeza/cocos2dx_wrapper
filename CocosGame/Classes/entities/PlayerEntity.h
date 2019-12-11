#ifndef __PLAYERENTITY_H__
#define __PLAYERENTITY_H__

#include "CEntity.h"

class PlayerEntity : public CEntity
{
public:
	PlayerEntity(const char* texturePath, float x, float y, CEntity* parent);
	PlayerEntity(std::vector<std::string> tokenizedElement, CEntity* parent);

	virtual bool init() override;
	virtual void update(float deltaTime) override;
};

#endif