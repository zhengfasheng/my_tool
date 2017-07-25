#pragma once
#include "ITest.h"
#include "Adapter.h"

#include <list>
using namespace std;

class AdapterTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "������ģʽ";
	}

	virtual void run() override
	{
		using namespace Adt;
		//ԭ�е�ҵ���߼�
		Target* pTarget = new ConcreteTarget;
		pTarget->request();

		//������������������ɫ���ҵ���߼�
		Target* pAdapter = new Adapter;
		pAdapter->request();
		delete pTarget;
		delete pAdapter;

		int* p = new int(1);
		int* p1 = new int(2);
		list<int*> l;
		l.push_back(p);
		l.push_back(p1);

		list<int*> l2;
		l2.push_back(new int(3));
		l2.push_back(new int(4));

		swap(l,l2);
	}
};