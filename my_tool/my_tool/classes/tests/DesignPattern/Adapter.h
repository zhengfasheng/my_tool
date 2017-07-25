#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
将一个类的接口转换成客户希望的另外一个接口。
Adapter模式使得原本由于接口不兼容
而不能一起工作的那些类可以一起工作

● Target目标角色
该角色定义把其他类转换为何种接口， 也就是我们的期望接口， 例子中的IUserInfo接口
就是目标角色。
● Adaptee源角色
你想把谁转换成目标角色， 这个“谁”就是源角色， 它是已经存在的、 运行良好的类或对
象， 经过适配器角色的包装， 它会成为一个崭新、 靓丽的角色。
● Adapter适配器角色
适配器模式的核心角色， 其他两个角色都是已经存在的角色， 而适配器角色是需要新建
立的， 它的职责非常简单： 把源角色转换为目标角色， 怎么转换？ 通过继承或是类关联的方
式。
*/
namespace Adt {

	//Target目标角色
	class Target
	{
	public: 
		Target(){}
		virtual ~Target(){}
		virtual void request() = 0;
	};

	//ConcreteTarget目标角色实例
	class ConcreteTarget : public Target
	{
	public:
		virtual void request() override
		{
			cout << "I'm a concrete target" << endl;
		}
	};

	//Adaptee源角色(被适配者)
	class Adaptee
	{
	public:
		Adaptee(){}
		virtual ~Adaptee(){}
		void doSomething()
		{
			cout << "I'm an adaptee" << endl;
		}
	};

	//适配器角色Adapter
	class Adapter : public Adaptee, public Target
	{
	public:
		virtual void request() override
		{
			doSomething();
		}
	};
}