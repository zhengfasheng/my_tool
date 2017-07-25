#pragma once
#include "ITest.h"
#include "Facade.h"

class FacadeTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "门面模式/外观模式";
	}
	virtual void run() override
	{
		using namespace Facade;

		auto p = new EncrytFile;
		p->fileEncrypt("test.txt", "out.txt");
		delete p;
	}
};