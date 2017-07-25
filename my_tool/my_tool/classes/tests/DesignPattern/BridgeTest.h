#pragma once
#include "ITest.h"
#include "Bridge.h"

class BridgeTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "ÇÅ½Ó/ÇÅÁºÄ£Ê½";
	}

	virtual void run() override
	{
		using namespace Bridge;

		Implementor* pImp = new ImplementorOne;
		Abstraction* pAbs = new RefindAbstraction(pImp);
		pAbs->request();
		delete pAbs;
	}
};