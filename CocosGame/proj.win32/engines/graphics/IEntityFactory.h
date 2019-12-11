#ifndef __IENTITYFACTORY_H__
#define __IENTITYFACTORY_H__

#include "Classes/entities/CEntity.h"
#include "Classes/entities/PlayerEntity.h"
#include "Classes/entities/AIEntity.h"

class IEntityFactory
{
public:
	virtual ~IEntityFactory() { };

	virtual CEntity*      createEntity      (const char* texturePath, float x, float y, CEntity* parent) const = 0;
	virtual CEntity*      createEntity      (std::vector<std::string> tokenizedElement, CEntity* parent) const = 0;

	virtual AIEntity*     createAIEntity    (const char* texturePath, float x, float y, CEntity* parent) const = 0;
	virtual AIEntity*     createAIEntity    (std::vector<std::string> tokenizedElement, CEntity* parent) const = 0;

	virtual PlayerEntity* createPlayerEntity(const char* texturePath, float x, float y, CEntity* parent) const = 0;
	virtual PlayerEntity* createPlayerEntity(std::vector<std::string> tokenizedElement, CEntity* parent) const = 0;

	virtual void removeCEntity(CEntity* entity) const = 0;
}; 

#endif