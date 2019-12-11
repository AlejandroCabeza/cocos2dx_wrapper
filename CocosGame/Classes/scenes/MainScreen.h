#ifndef __MAINSCREEN_H__
#define __MAINSCREEN_H__

#include "CSreen.h"

class MainScreen : public CScreen
{
public:
	MainScreen();
	virtual ~MainScreen();

	virtual bool init  ()                override;
	virtual void update(float deltaTime) override;
};

#endif