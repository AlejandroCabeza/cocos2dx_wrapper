#include "CGraphics.h"

#include "CTextureManager.h"
#include "CSpriteFactory.h"
#include "CEntityFactory.h"
#include "CComponentFactory.h"

#include "cocos2d.h"
#include <scenes/MainScreen.h>

CGraphics::~CGraphics()
{
	ISpriteFactory* spriteFactory = CSpriteFactory::getInstance();
	SAFE_DELETE(spriteFactory);

	ITextureManager* textureManager = CTextureManager::getInstance();
	SAFE_DELETE(textureManager);

	IEntityFactory* entityFactory = CEntityFactory::getInstance();
	SAFE_DELETE(entityFactory);

	IComponentFactory* componentFactory = CComponentFactory::getInstance();
	SAFE_DELETE(componentFactory);
}

void CGraphics::drawLine(float x, float y, float x2, float y2) const
{
	cocos2d::ccDrawLine(cocos2d::Vec2(x, y), cocos2d::Vec2(x2, y2));
}

// ReSharper disable once CppMemberFunctionMayBeStatic
void CGraphics::menuCloseCallback(const cocos2d::Ref* pSender) const
{
	cocos2d::Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

CGraphics::CGraphics()
{
	mScene      = nullptr;
}

void CGraphics::drawExitButton() const
{
	ASSERT_MSG(mScene, "Scene not defined to link entities to.");
	auto closeItem = cocos2d::MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(CGraphics::menuCloseCallback, this));

	closeItem->setPosition(cocos2d::Vec2(getScreenVisibleOrigin().getX() + getScreenVisibleSize().getX() - closeItem->getContentSize().width / 2,
		getScreenVisibleOrigin().getY() + closeItem->getContentSize().height / 2));

	auto menu = cocos2d::Menu::create(closeItem, NULL);
	menu->setPosition(cocos2d::Vec2::ZERO);
	mScene->addChild(menu, 1);
}

void CGraphics::createScene()
{
	mScene = cocos2d::Scene::create();
	cocos2d::Director::getInstance()->runWithScene(mScene);
}

cocos2d::Scene* CGraphics::getScene()
{
	if (!mScene) createScene();
	return mScene;
}

Vector2D CGraphics::getScreenVisibleSize() const
{
	cocos2d::Size size = cocos2d::Director::getInstance()->getWinSize();
	return Vector2D(size.width, size.height);
}

Vector2D CGraphics::getScreenVisibleOrigin() const
{
	cocos2d::Vec2 vec = cocos2d::Director::getInstance()->getVisibleOrigin();
	return Vector2D(vec.x, vec.y);
}

ITextureManager* CGraphics::getTextureManager() const
{
	return CTextureManager::getInstance();
}

ISpriteFactory* CGraphics::getSpriteFactory() const
{
	return CSpriteFactory::getInstance();
}

IEntityFactory* CGraphics::getEntityFactory() const
{
	CEntityFactory* entityFactory = CEntityFactory::getInstance();
	entityFactory->setScene(mScene);
	return entityFactory;
}

IComponentFactory * CGraphics::getComponentFactory() const
{
	return CComponentFactory::getInstance();
}
