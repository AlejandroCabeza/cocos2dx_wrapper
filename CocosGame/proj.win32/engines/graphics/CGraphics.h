#ifndef __CGRAPHICS_H__
#define __CGRAPHICS_H__

#include "IGraphics.h"

#include "cocos2d.h"
#include "Classes/scenes/MainScreen.h"

class CGraphics : public IGraphics
{
private:
	cocos2d::Scene* mScene;
	MainScreen*     mGameScreen;

	void menuCloseCallback(const cocos2d::Ref* pSender)         const;

public:
	CGraphics();
	virtual ~CGraphics();

	virtual void drawLine(float x, float y, float x2, float y2) const override;

	virtual void drawExitButton()                               const override;

	virtual void    createScene()                                     override;
	cocos2d::Scene* getScene   ();

	virtual Vector2D getScreenVisibleSize  ()                   const override;
	virtual Vector2D getScreenVisibleOrigin()                   const override;

	virtual ITextureManager*   getTextureManager  ()            const override;
	virtual ISpriteFactory*    getSpriteFactory   ()            const override;
	virtual IEntityFactory*    getEntityFactory   ()            const override;
	virtual IComponentFactory* getComponentFactory()            const override;
};

#endif