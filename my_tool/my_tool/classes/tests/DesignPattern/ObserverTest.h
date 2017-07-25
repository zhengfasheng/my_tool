#pragma once
#include "ITest.h"
#include "Observer.h"

class ObserverTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "观察者模式";
	}

	virtual void run() override
	{
		using namespace Observer;

		auto pPeople = new PeopleDaily;
		auto pXiaoMing = new Subscriber("小明");
		auto pLiSi = new Subscriber("李四");
		auto pWanger = new Subscriber("王二");

		pPeople->addSubscriber(pXiaoMing);

		pPeople->addSubscriber(pXiaoMing);

		pPeople->addSubscriber(pLiSi);

		pPeople->addSubscriber(pWanger);

		pPeople->sendPaper();

		
		pPeople->removeSubscriber(pWanger);

		pPeople->sendPaper();

		auto pGuangming = new GuangmingDaily;

		pGuangming->addSubscriber(pXiaoMing);
		pGuangming->addSubscriber(pLiSi);
		pGuangming->sendPaper();


		delete pXiaoMing;
		delete pLiSi;
		delete pWanger;
		delete pPeople;
		delete pGuangming;

	}
};