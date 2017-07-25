#pragma once
#include "IHuman.h"
class BlackHuman :
	public IHuman
{
public:
	BlackHuman();
	~BlackHuman();
	virtual void getColor() override;
	virtual void talk() override;
};

