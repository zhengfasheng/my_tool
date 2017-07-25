#pragma once
#include "ITest.h"
#include "Delegate.h"

class DelegateTest :
	public ITest
{
public:
	virtual std::string getName() override
	{
		return "����ģʽ";
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