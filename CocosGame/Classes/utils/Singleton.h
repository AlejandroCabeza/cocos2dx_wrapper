#ifndef __SINGLETON__H_
#define __SINGLETON__H_

#include "Globals.h"

template <typename T>
class Singleton
{
protected:
	static T* mInstance;

public:
	static T* getInstance()
	{
		if (!mInstance) mInstance = SAFE_NEW(T);
		ASSERT_MSG(mInstance, "Failed to allocate pointer memory.");
		return mInstance;
	}
};

template <typename T>
T* Singleton<T>::mInstance = nullptr;

#endif