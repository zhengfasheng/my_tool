#pragma once
#include "ITest.h"
#include "Strategy.h"

class StrategyTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "²ßÂÔÄ£Ê½";
	}

	virtual void run( ) override
	{
		using namespace Strategy;
		IStrategy* pStrategy = new AirplaneStrategy;
		auto pPerson = new PersonContext(pStrategy);

		pPerson->travel();

		pStrategy = new TrainStrategy;
		pPerson->changeTravelStrategy(pStrategy);
		pPerson->travel();

		pStrategy = new BicycleStrategy;
		pPerson->changeTravelStrategy(pStrategy);
		pPerson->travel();

		delete pPerson;
	}
};