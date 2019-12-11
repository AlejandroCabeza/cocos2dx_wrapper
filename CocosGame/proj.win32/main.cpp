#include "main.h"
#include "AppDelegate.h"
#include "cocos2d.h"

#include "Globals.h"

USING_NS_CC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	
    // create the application instance
    AppDelegate app;




	auto returnValue = Application::getInstance()->run();

	return returnValue;
}
