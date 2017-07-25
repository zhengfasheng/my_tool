#pragma once
#include "ITest.h"
#include "boost/progress.hpp"
#include <fstream>

class TestProgress : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestProgress);
	virtual void run() override
	{
		vector<string> v(100,"zheng fa sheng");
		ofstream fs("test.txt");

		boost::progress_display dis(v.size());

		auto it = v.begin();
		for (; it != v.end();++it)
		{
			fs << *it << endl;
			++dis;
		}
		fs.close();
	}
};
