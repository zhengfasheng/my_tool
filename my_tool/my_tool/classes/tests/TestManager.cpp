#include "TestManager.h"
#include "BoostManager.h"
#include "C11Manager.h"
#include "DataStructureManager.h"
#include "DesignPatternManager.h"
#include "OtherManager.h"

void TestManager::registerManger()
{
	RIGISTER_MANAGER(BoostManager);
	RIGISTER_MANAGER(C11Manager);
	RIGISTER_MANAGER(DataStructureManager);
	RIGISTER_MANAGER(DesignPatternManager);
	RIGISTER_MANAGER(OtherManager);
}

TestManager::TestManager()
{
	cout << "TestManager::TestManager" << endl;
}

TestManager::~TestManager()
{
	m_managers.clear();
}

void TestManager::run()
{
	registerManger();
	excuteManager();
}

void TestManager::registerManger(IManager* pManager)
{
	auto it = std::find(m_managers.begin(), m_managers.end(), pManager);
	if ( it == m_managers.end() )
	{
		m_managers.push_back(pManager);
	}
}

void TestManager::excuteManager()
{
	for (size_t i = 0; i < m_managers.size(); i++ )
	{
		auto pManager = m_managers[i];
		if ( pManager )
		{
			pManager->run();
			pManager->destory();
		}
	}
}

