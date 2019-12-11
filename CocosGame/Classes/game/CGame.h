#ifndef __CGAME_H__
#define __CGAME_H__

#include "proj.win32/engines/manager/CManager.h"

class CGame
{
private:
	CManager* mManager;

public:
	CGame();
	~CGame();

	bool init() const;
};

#endif
