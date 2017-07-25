#pragma once
#include "ITest.h"
#include "Mediator.h"
using namespace std;
class MediatorTest : public ITest 
{
public:
	virtual std::string getName() override
	{
		return "中介者模式";
	}

	virtual void run() override
	{
		using namespace Mediator;

		IMediator* pMediator = new HouseMediator;

		auto pHouse1 = new House;

		auto pLandlord1 = new Landlord("张三", pMediator,nullptr);
		pLandlord1->setHouse(pHouse1);
		pHouse1->setOwner(pLandlord1);

		pMediator->addHouseOwner(pLandlord1);

		auto pHouse2 = new House;
		auto pLandlord2 = new Landlord("李四", pMediator, pHouse2);
		pLandlord2->setHouse(pHouse2);
		pHouse2->setOwner(pLandlord2);

		pMediator->addHouseOwner(pLandlord2);

		auto pRenter = new Renter("小李子", pMediator);
		pMediator->addRenter(pRenter);

		pLandlord1->lease();
		pLandlord2->lease();

		pRenter->rentByPrice(1800);

		delete pMediator;

	}
};