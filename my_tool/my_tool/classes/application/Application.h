#pragma once
#include "common.h"

class AppDelegate;
class Application
{
public:
	~Application();
	static Application* getInstance();

	void run( );

private:

	void init();
	Application();

private:
	AppDelegate* m_pAppDelegate;

};