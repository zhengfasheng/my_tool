#include "C11Manager.h"
#include "TestC11.h"
#include "TestFunction.h"

void C11Manager::registerTest()
{
	RIGISTER_TEST(TestC11);
	RIGISTER_TEST(TestFunction);
}

