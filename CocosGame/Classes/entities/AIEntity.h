#ifndef __AIENTITY_H__
#define __AIENTITY_H__

#include "CEntity.h"

class AIEntity : public CEntity
{
public:
	AIEntity(const char* texturePath, float x, float y, CEntity* parent);
	AIEntity(std::vector<std::string> tokenizedElement, CEntity* parent);

	bool init() override;
	void update(float deltaTime) override;
};

#endif
