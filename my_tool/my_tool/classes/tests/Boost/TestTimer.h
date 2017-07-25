#pragma once
#include "ITest.h"
#include "boost/progress.hpp"

class TestTimer : public ITest
{
public:
	TestTimer();
	~TestTimer();
	IMPLEMENT_GET_NAME(TestTimer);

	virtual void run() override;

};

//系统默认只支持两位小数
template< unsigned N = 2>
class my_progress_timmer : public boost::progress_timer
{
public:
	my_progress_timmer(ostream& os = std::cout) :m_os(os)
	{
		BOOST_HAS_STATIC_ASSERT(N >= 0 && N <= 10);
	}
	~my_progress_timmer()
	{
		try
		{
			//保存流的状态
			iostream::fmtflags old_flags = m_os.setf(iostream::fixed, iostream::floatfield);
			streamsize old_prec = m_os.precision(N);
			//输出时间
			m_os << elapsed() << "s" << endl;
			//恢复流状态
			m_os.flags(old_flags);
			m_os.precision(old_prec);
		}
		catch (...){};
	}

private:

	ostream& m_os;
};

class pro_timer : public my_progress_timmer<10>{};