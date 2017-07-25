#pragma once
#include "ITest.h"
#include "Observer.h"

class ObserverTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "�۲���ģʽ";
	}

	virtual void run() override
	{
		using namespace Observer;

		auto pPeople = new PeopleDaily;
		auto pXiaoMing = new Subscriber("С��");
		auto pLiSi = new Subscriber("����");
		auto pWanger = new Subscriber("����");

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