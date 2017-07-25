#include "TestFunction.h"

class A
{
public:
	A(const function<void(int)> & func) :callback(func)
	{

	}
	~A(){

	}

	void notify(int value)
	{
		callback(value);
	}

	function<void(int)> callback;
private:

};


void func(int value){
	cout << "This value is " << value << endl;
}

int call_when_even(int x, const function<int(int)> &f)
{
	if (x == 1)
	{
		return f(x);
	}
	else
	{
		return x;
	}

}

int funcAdd(int x){
	return x + 1;
}

void output(int x, int y)
{
	std::cout << x << " " << y << std::endl;
}

void outputEx(int x, int y, int z, int k)
{
	std::cout << x << " " << y << " " << z << " " << k << " " << std::endl;
}

class AA
{
	int _i;
	int _j;
	int _k;
	int _x;
public:
	AA(int i, int j, int k, int x) :_i(i), _j(j), _k(k), _x(x){}
	AA(int i, int j, int k) :AA(i, j, k, 1){}

	void printl()
	{
		auto &tempi = _i;
		auto func = [&tempi](){
			tempi = 10;
		};

		func();
		cout << _i << endl;

	}

	~AA(){}
};

void TestFunction::run()
{
	A a(func);
	a.notify(10);

	int i = 1;
	cout << call_when_even(i++, funcAdd) << endl;
	cout << call_when_even(i, funcAdd) << endl;

	std::bind(output, 1, 2)(); // 输出 : 1 2
	auto callback = std::bind(output, 1, 2); // 输出 : 1 2
	callback(33, 3, "zheg");
	std::bind(output, std::placeholders::_1, 2)(10); // 输出 : 1 2
	std::bind(outputEx, 2, 4, 5, std::placeholders::_1)(1); // 输出 : 2 1
	// error: 调用时没有第二个参数
	//std::bind(output, 2, std::placeholders::_3)(1);//编译不过
	std::bind(output, 3, std::placeholders::_3)(1, 5, 20); // 输出 : 3 20
	// 调用时的第一个参数被吞掉了
	std::bind(output, std::placeholders::_1, std::placeholders::_2)(1, 2); // 输出 : 1 2
	std::bind(output, std::placeholders::_2, std::placeholders::_1)(1, 2); // 输出 : 2 1


	cout << "------------------------" << endl;

	int value = 1;

	auto func = [&value]() -> int {
		value = 2;
		return 1;
	};



	cout << func() << endl;

	cout << value << endl;

	//BB b(2.0);

	//cout << b.getFloat() << endl;


	AA aa(1, 2, 3, 4);
	aa.printl();
}

