
#include "ITest.h"

//斐波纳契数
template<unsigned N> struct Fib
{
	enum
	{
		Val = Fib<N - 1>::Val + Fib<N - 2>::Val
	};
};

template<> struct Fib<0>
{
	enum
	{
		Val = 0
	};
};

template<> struct Fib<1>
{
	enum
	{
		Val = 1
	};
};

#define FibT( n ) Fib<n>::Val

//阶乘
template<unsigned N> struct Fact
{
	enum { Val = N * Fact<N - 1>::Val };
};

template<> struct Fact<1>
{
	enum
	{
		Val = 1
	};
};

#define FactT( n ) Fact<n>::Val 

//前n项和
class TestTemplate : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestTemplate);
	virtual void run() override;
};

template<unsigned N>
struct SumCount
{
	enum 
	{
		Val = N + SumCount<N -1>::Val
	};
};

template<>
struct SumCount<0>
{
	enum { Val = 0 };
};


#define SumT( n ) SumCount<n>::Val 