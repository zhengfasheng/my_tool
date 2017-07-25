#pragma once
#include "ITest.h"
#include "Delegate.h"

class DelegateTest :
	public ITest
{
public:
	virtual std::string getName() override
	{
		return "代理模式";
	}

	virtual void run() override
	{
		using namespace Delegate;
		Subject* pRealSubject = new RealSubject;
		Subject* pProxy = new Proxy(pRealSubject);
		pProxy->request();
		delete pProxy;

	}
};