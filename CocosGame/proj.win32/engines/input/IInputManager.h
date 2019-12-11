#ifndef __IINPUTMANAGER_H__
#define __IINPUTMANAGER_H__

#include <functional>

class IInputManager
{
public:
	virtual ~IInputManager() { };

	enum EventType
	{
		TouchDown,
		TouchUp,
		TouchMove,
		None
	};

	virtual bool init() = 0;

	virtual unsigned int subscribeToTouchEvents(std::function<void(EventType eventType, int x, int y)> func) = 0;
	virtual void         removeFromTouchEvents (unsigned int id)                                             = 0;
};

#endif