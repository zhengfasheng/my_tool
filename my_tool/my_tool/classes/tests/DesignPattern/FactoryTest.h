#pragma once
#include "ITest.h"
#include "HumanFactory.h"
#include "BlackHuman.h"
#include "YellowHuman.h"
#include "WhiteHuman.h"
class FactoryTest :
	public ITest
{
public:
	FactoryTest(){}
	~FactoryTest(){}
	virtual std::string getName() override
	{
		return "工厂模式";
	}
	virtual void run() override
	{
		IHumanFactory* factory = new HumanFactory;

		IHuman* human = factory->createHuman<BlackHuman>();

		if (human)
		{
			human->getColor();
			human->talk();
		}

		delete human;

		human = factory->createHuman<YellowHuman>();
		if (human)
		{
			human->getColor();
			human->talk();
		}

		delete human;

		human = factory->createHuman<WhiteHuman>();
		if (human)
		{
			human->getColor();
			human->talk();
		}

		delete human;
		human = nullptr;
	}
};

