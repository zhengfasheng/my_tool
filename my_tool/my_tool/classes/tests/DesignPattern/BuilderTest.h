#pragma once
#include "ITest.h"
#include "Builder.h"
using namespace Builder;

class BuilderTest :
	public ITest
{
public:
	virtual std::string getName() override
	{
		return "建造者模式";
	}
	virtual void run() override
	{
		IPersonBuilder* pBuilder = new MalePersonBuilder;
		PersonDirector* pDirector = new PersonDirector;
		Person* pPerson = pDirector->builderPerson(pBuilder);

		pPerson->display();

		delete pBuilder;

		pBuilder = new FemalePersonBuilder;
		pPerson = pDirector->builderPerson(pBuilder);
		pPerson->display();
		delete pBuilder;
		delete pDirector;

	}
};