#pragma once
class IHuman
{
public:
	IHuman(){}
	virtual ~IHuman(){}
	virtual void getColor() = 0;
	virtual void talk() = 0;
};

