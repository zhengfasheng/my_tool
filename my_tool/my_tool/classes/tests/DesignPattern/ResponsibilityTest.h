#pragma once
#include "ITest.h"
#include "Responsibility.h"
#include <random>
#include <array>

class ResponsibilityTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "责任链模式";
	}

	virtual void run() override
	{
		using namespace Responsibility;

		std::default_random_engine dre;
		std::uniform_int_distribution<int> di(0,Widow);
		array<IWomen*,5> arrayList;
		for (size_t i = 0; i < arrayList.size() ; i++ )
		{
			arrayList[i] = new Women((Type)di(dre), "我要出去逛街");
		}

		IHandler* pFather = new Father;
		IHandler* pHusband = new Husband;
		IHandler* pSon = new Son;

		pFather->setNext(pHusband);
		pHusband->setNext(pSon);

		for ( auto o : arrayList )
		{
			pFather->handleMessage(o);
		}

		for (size_t i = 0; i < arrayList.size(); i++)
		{
			IWomen* p = arrayList[i];
			if ( p )
			{
				delete p;
				p = nullptr;
			}
		}
		
		delete pFather;
		delete pHusband;
		delete pSon;

	}
};