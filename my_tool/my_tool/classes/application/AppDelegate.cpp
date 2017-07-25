#include "AppDelegate.h"
#include "TestManager.h"

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{

}

void AppDelegate::run()
{
	TestManager::getInstance()->run(); 
	getchar();
}

bool AppDelegate::init()
{
	return true;
}
