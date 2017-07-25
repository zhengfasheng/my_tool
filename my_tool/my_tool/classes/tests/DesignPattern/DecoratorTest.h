#pragma once
#include "ITest.h"
#include "Decorator.h"

class DecoratorTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "装饰者模式";
	}

	virtual void run() override
	{
		using namespace Decorator;
		//浓咖啡
		Beverage* pBeverage = new Espresso;
		pBeverage->display();

		Beverage* pHouseBlend = new HouseBlend;
		pHouseBlend = new Mocha(pHouseBlend);
		pHouseBlend = new Mocha(pHouseBlend);
		pHouseBlend = new Whip(pHouseBlend);
		
		pHouseBlend->display();
		delete pBeverage;
		delete pHouseBlend;

	}
};