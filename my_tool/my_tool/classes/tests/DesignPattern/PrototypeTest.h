#pragma once
#include "ITest.h"
#include "Prototype.h"

class PrototypeTest :
	public ITest
{
public:
	virtual std::string getName() override
	{
		return "ԭ��ģʽ";
	}


	virtual void run() override
	{
		using namespace Prototype;

		Control* pContro1 = new Button(12.f, 12.f, 200.f, 300.f);
		pContro1->display();

		Control* pClone = pContro1->clone();
		delete pContro1;

		pClone->display();

		pClone->setHeight(100);

		pClone->display();

		delete pClone;
	}
};
