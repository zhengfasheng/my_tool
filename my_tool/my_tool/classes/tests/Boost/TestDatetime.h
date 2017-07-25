#pragma once
#include "ITest.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <exception>
#include "boost/any.hpp"

class TestDatetime : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestDatetime)
	virtual void run() override
	{
		using namespace boost::gregorian;
		date d1;
		cout << d1 << endl;

		cout << to_simple_string(d1) << endl;

		date d2(2012, 1, 1);
		cout << d2 << endl;

		cout << to_simple_string(d2) << endl;
		cout << to_iso_string(d2) << endl;
		cout << to_iso_extended_string(d2) << endl;

		date d3(2013, Jan, 1);
		cout << d3 << endl;

		tm t = to_tm(d3);
		cout << t.tm_year + 1900 << "-" << t.tm_mon + 1 << "-" << t.tm_mday << endl;


		date d4 = date_from_tm(t);

		cout << to_iso_extended_string(d4) << endl;

	
		try
		{
			date d4 = from_string("2014-2-29");
			cout << d4 << endl;
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		
		struct MyStruct
		{
			int a = 2;
			int b = 34;
		};

		MyStruct myStru;
		boost::any a = &myStru;

		a = 12;
		a = "298793978979";
		boost::any b;
		b = a;
	}
};