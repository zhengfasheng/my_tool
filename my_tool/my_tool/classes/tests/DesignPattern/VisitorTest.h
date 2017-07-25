#pragma once
#include "ITest.h"
#include "Visitor.h"

class VisitorTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "访问者模式";
	}

	virtual void run() override
	{
		using namespace visitor;

		auto pElements = ObjectStruture::getInstance()->getElements();

		for ( auto pElement : pElements )
		{
			if ( pElement )
			{
				pElement->accept(new Visitor);
			}
		}
		ObjectStruture::getInstance()->release();
	}
};