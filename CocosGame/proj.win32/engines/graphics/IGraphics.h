#ifndef __IGRAPHICS__H_
#define __IGRAPHICS__H_

#include "ITextureManager.h"
#include "ISpriteFactory.h"
#include "IEntityFactory.h"
#include "IComponentFactory.h"

#include "Classes/utils/Vector2D.h"

class IGraphics
{
public:
	virtual ~IGraphics() { };

	virtual void drawLine  (float x, float y, float x2, float y2) const = 0;

	virtual void drawExitButton()								  const = 0;

	virtual void createScene()                                          = 0;

	virtual Vector2D getScreenVisibleSize  ()                     const = 0;
	virtual Vector2D getScreenVisibleOrigin()					  const = 0;

	virtual ITextureManager*   getTextureManager  ()              const = 0;
	virtual ISpriteFactory*    getSpriteFactory   ()              const = 0;
	virtual IEntityFactory*    getEntityFactory   ()              const = 0;
	virtual IComponentFactory* getComponentFactory()              const = 0;
};

#endif