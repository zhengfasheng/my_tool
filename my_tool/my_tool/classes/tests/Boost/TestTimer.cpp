#include "TestTimer.h"
#include "boost/timer.hpp"
#include "boost/any.hpp"

TestTimer::TestTimer()
{

}

TestTimer::~TestTimer()
{

}

void TestTimer::run()
{
	using namespace boost;

	any value = 11;
	
	auto rValue = any_cast<int>(value);

	//return;
	boost::timer t;
	cout << "max timespan:" << t.elapsed_max() << endl;
	cout << "min timespan:" << t.elapsed_min() << endl;

	cout << "not time elapsed:" << t.elapsed() << endl;

	{
		boost::progress_timer pt;
		int n = 100000;
		while (n--);
	}

	{
		pro_timer pt;
		int n = 100000000;
		while (n--);
	}
}

