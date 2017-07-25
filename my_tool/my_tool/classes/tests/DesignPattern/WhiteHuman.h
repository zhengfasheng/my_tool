#pragma once
#include "IHuman.h"
class WhiteHuman :
	public IHuman
{
public:
	WhiteHuman();
	~WhiteHuman();
	virtual void getColor() override;
	virtual void talk() override;
};

