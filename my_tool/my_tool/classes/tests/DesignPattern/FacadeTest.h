#pragma once
#include "ITest.h"
#include "Facade.h"

class FacadeTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "����ģʽ/���ģʽ";
	}
	virtual void run() override
	{
		using namespace Facade;

		auto p = new EncrytFile;
		p->fileEncrypt("test.txt", "out.txt");
		delete p;
	}
};