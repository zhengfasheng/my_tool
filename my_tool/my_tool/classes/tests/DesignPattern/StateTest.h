#pragma once
#include "ITest.h"
#include "State.h"

class StateTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "״̬ģʽ";
	}

	virtual void run() override
	{
		using namespace State;

		auto pLift = new Context;
		pLift->setState(Context::s_pStopState);
		pLift->open();
		pLift->close();
		pLift->run();
		pLift->stop();
		delete pLift;
	}
}; 