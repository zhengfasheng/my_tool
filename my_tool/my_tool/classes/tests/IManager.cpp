#include "IManager.h"
#include "Itest.h"
IManager::IManager()
{

}

IManager::~IManager()
{
	destory();
}

void IManager::run()
{
	if (isUsing())
	{
		cout << "----------- " << this->getName()
			<< " -----------" << endl;
		this->registerTest();
		this->excuteTest();
	}
}

void IManager::registerTest(ITest* pTest)
{
	m_tests.push_back(pTest);
}

void IManager::destory()
{
	for (size_t i = 0; i < m_tests.size(); i++)
	{
		auto& pTest = m_tests[i];
		if ( pTest )
		{
			delete pTest;
		}
		pTest = nullptr;
	}
	m_tests.clear();
}

void IManager::excuteTest()
{
	for (size_t i = 0; i < m_tests.size(); i++)
	{
		auto pTest = m_tests[i];
		if ( pTest )
		{
			cout << "----------- " << pTest->getName()
				<< " -----------" << endl;
			pTest->run();
		}
	}
}

