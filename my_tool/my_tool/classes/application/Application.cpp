#include "Application.h"
#include "AppDelegate.h"

Application::Application()
	:m_pAppDelegate( nullptr )
{

}

Application::~Application()
{
	if (m_pAppDelegate)
		delete m_pAppDelegate;
	m_pAppDelegate = nullptr;
}

void Application::run()
{
	if ( m_pAppDelegate )
	{
		if ( m_pAppDelegate->init() )
		{
			m_pAppDelegate->run();
		}
		else
		{
			cout << "app delegate init fail" << endl;
		}
	}
	else
	{
		cout << "you must create an app delegate" << endl;
	}
	//while (true)
	getchar();
}


void Application::init()
{
	m_pAppDelegate = new AppDelegate;
}

Application* Application::getInstance()
{
	static Application* pInstance = nullptr;
	if ( !pInstance )
	{
		pInstance = new Application;
		pInstance->init();
	}
	return pInstance;
}
