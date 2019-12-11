#ifndef __CINPUTMANAGER_H__
#define __CINPUTMANAGER_H__

#include "IInputManager.h"

#include <vector>

#include "cocos2d.h"

class CInputManager : public IInputManager
{
private:

	struct TouchListener
	{
		unsigned int mId;
		std::function<void(EventType, int x, int y)> mFunc;

		TouchListener(unsigned int id, std::function<void(EventType, int x, int y)> func)
		{
			mId   = id;
			mFunc = func;
		}
	};

	unsigned int                         mIdGenerator;
	std::vector<TouchListener>           mVectorTouchListeners;

	cocos2d::EventListenerTouchOneByOne* mTouchListener;
	cocos2d::Scene*                      mScene;

public:
	CInputManager(cocos2d::Scene* scene = nullptr);
	~CInputManager();

	bool init() override;

	virtual unsigned int subscribeToTouchEvents(std::function<void(EventType, int x, int y)> func) override;
	virtual void         removeFromTouchEvents (unsigned int id)                                   override;
};

#endif