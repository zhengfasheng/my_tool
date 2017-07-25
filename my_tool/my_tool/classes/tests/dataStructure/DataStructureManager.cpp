#include "DataStructureManager.h"
#include "MyList.h"
#include "Review.h"
#include "Tree.h"

void DataStructureManager::registerTest()
{
	RIGISTER_TEST(TestMyList);
	RIGISTER_TEST(TestReview);
	RIGISTER_TEST(TestTree);
}

