#ifndef __CENTITYFACTORY_H__
#define __CENTITYFACTORY_H__

#include "IEntityFactory.h"

#include "Classes/utils/Singleton.h"
#include "cocos2d.h"

class CEntityFactory : public IEntityFactory, public Singleton<CEntityFactory>
{
private:
	cocos2d::Scene* mScene;

public:
	virtual CEntity *     createEntity      (const char* texturePath, float x, float y, CEntity* parent) const override;
	virtual CEntity*      createEntity      (std::vector<std::string> tokenizedElement, CEntity* parent) const override;

	virtual AIEntity*     createAIEntity    (const char* texturePath, float x, float y, CEntity* parent) const override;
	virtual AIEntity*     createAIEntity    (std::vector<std::string> tokenizedElement, CEntity* parent) const override;

	virtual PlayerEntity* createPlayerEntity(const char* texturePath, float x, float y, CEntity* parent) const override;
	virtual PlayerEntity* createPlayerEntity(std::vector<std::string> tokenizedElement, CEntity* parent) const override;

	virtual void removeCEntity(CEntity* entity) const override;

	void setScene(cocos2d::Scene* scene);
};

#endif