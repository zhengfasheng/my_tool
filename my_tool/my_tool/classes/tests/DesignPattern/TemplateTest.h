#pragma once
#include "ITest.h"
#include "Template.h"
using namespace Template;
class TemplateTest :
	public ITest
{
public:
	TemplateTest(){}
	~TemplateTest(){}
	virtual std::string getName() override
	{
		return "Ä£°åÄ£Ê½";
	}
	virtual void run() override
	{
		IClass* pClass = new ConcreteOne;
		pClass->operation();
		
		SAVE_DELETE(pClass);

		pClass = new ConcreteTwo;
		pClass->operation();
		SAVE_DELETE(pClass);
	}
};

