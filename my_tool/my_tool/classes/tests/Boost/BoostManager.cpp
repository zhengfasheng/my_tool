#include "BoostManager.h"
#include "TestDatetime.h"
#include "TestProgress.h"
#include "TestTemplate.h"
#include "TestTimer.h"

BoostManager::BoostManager()
{

}

BoostManager::~BoostManager()
{

}

void BoostManager::registerTest()
{
	RIGISTER_TEST(TestDatetime);
	RIGISTER_TEST(TestProgress);
	RIGISTER_TEST(TestTemplate);
	RIGISTER_TEST(TestTimer);
}


