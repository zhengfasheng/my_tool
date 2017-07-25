#pragma once
#include "ITest.h"
#include "Iterator.h"
#include <exception>
#include "SimpleIterator.h"

class IteratorTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "µü´úÆ÷Ä£Ê½";
	}

	virtual void run() override
	{
		using namespace Iterator;

		List<std::string> list;
		list.push_back("23424");
		list.push_back("3455");
		cout << list << endl;

		try
		{
			cout << list[0] << endl;
			cout << list[1] << endl;
			cout << list[2] << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		

		for (auto it = list.begin(); it != list.end(); it++ )
		{
			cout << *it << endl;
		}

		list.remove("3455");
		cout << list << endl;

		list.insert(list.end(), "283848");

		cout << list << endl;
		list.insert(--list.end(), "3333");

		cout << list << endl;
		cout << "size:" << list.size() << endl;


		List<int> l2;
		l2.push_back(2);

		cout << l2[0] << endl;


		using namespace SimpleIterator;

		Waitress* pWaitress = new Waitress;
		pWaitress->printMenu();

		delete pWaitress;


	}
};