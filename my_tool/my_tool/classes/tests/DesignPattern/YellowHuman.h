#pragma once
#include "IHuman.h"
class YellowHuman :
	public IHuman
{
public:
	YellowHuman();
	~YellowHuman();
	virtual void getColor() override;

	virtual void talk() override;
};

