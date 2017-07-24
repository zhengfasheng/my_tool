#include "AppDelegate.h"
#include "Any.h"
//#include "TestOne.h"
//#include "TestAsyncOne.h"
//#include "TestAsyncTwo.h"
//#include "TestAsyncThree.h"
//#include "TestSharedfuture.h"
//#include "TestThread.h"
//#include "TestSingleton.h"
//#include "SimpleSingleton.h"
//#include "SimpleFactory.h"
//#include "TestCompare.h"

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{

}

void AppDelegate::run()
{
	//for (int i = 0; i < 100; i++)
	//{
	//	std::async([]{
	//		//TestSingleton::getInstance()->run();
	//		SimpleSingleton::getInstance();
	//	});
	//}
	//getchar();
	boost::any a;

	for (auto pTest : m_tests)
	{
		if (pTest)
		{
			//cout << "----------  " << pTest->getName() << "  ----------" << endl;
			//pTest->run();
		}
	}
}

bool AppDelegate::init()
{
	//m_tests.push_back(new TestOne);
	//m_tests.push_back(new TestAsyncOne);
	//m_tests.push_back(new TestAsyncTwo);
	//m_tests.push_back(new TestAsyncThree);
	//m_tests.push_back(new TestSharedfuture);
	//m_tests.push_back(new TestThread);
	//m_tests.push_back(new TestSimpleFactory);
	//m_tests.push_back(new TestCompare);
	return true;
}
