#pragma once
class IHuman;
class IHumanFactory
{
public:
	IHumanFactory(){}
	virtual ~IHumanFactory(){}
	template<class T>
	IHuman* createHuman(){
		return new T;
	}
};

