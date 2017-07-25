#pragma once
#include "ITest.h"
#include "Flyweight.h"

class FlyweightTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "ÏíÔªÄ£Ê½";
	}

	virtual void run() override
	{
		using namespace Flyweight;

		auto pFlyweight1 = FlyweightFactory::getInstance()->getFlyweight<FlyweightObjectOne>("zheng");
		auto pFlyweight2 = FlyweightFactory::getInstance()->getFlyweight<FlyweightObjectTwo>("zheng");
		auto pFlyweight3 = FlyweightFactory::getInstance()->getFlyweight<FlyweightObjectOne>("zheng");
		auto pFlyweight4 = FlyweightFactory::getInstance()->getFlyweight<FlyweightObjectTwo>("zheng");

		FlyweightFactory::getInstance()->release();

	}
};