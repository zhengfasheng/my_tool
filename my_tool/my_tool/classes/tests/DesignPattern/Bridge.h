#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
桥接/桥梁模式
将抽象和实现解耦， 使得两者可以独立地变化。

● Abstraction——抽象化角色
它的主要职责是定义出该角色的行为， 同时保存一个对实现化角色的引用， 该角色一般
是抽象类。
● Implementor——实现化角色
它是接口或者抽象类， 定义角色必需的行为和属性。
● RefinedAbstraction——修正抽象化角色
它引用实现化角色对抽象化角色进行修正。
● ConcreteImplementor——具体实现化角色
它实现接口或抽象类定义的方法和属性。


*/

namespace Bridge
{
	//Implementor——实现化角色
	class Implementor
	{
	public:
		Implementor(){}
		virtual ~Implementor(){}
		virtual void doSomething() = 0;
		virtual void doAnything() = 0;
	};

	//ConcreteImplementor——具体实现化角色
	class ImplementorOne : public Implementor
	{
	public:
		~ImplementorOne()
		{
			cout << "~ImplementorOne()" << endl;
		}
		virtual void doSomething() override
		{
			cout << "ImplementorOne do something\n";
		}
		virtual void doAnything() override
		{
			cout << "ImplementorOne do anything\n";
		}
	};

	class ImplementorTwo : public Implementor
	{
	public:
		virtual void doSomething() override
		{
			cout << "ImplementorTwo do something\n";
		}
		virtual void doAnything() override
		{
			cout << "ImplementorTwo do anything\n";
		}
	};

	//Abstraction——抽象化角色
	class Abstraction
	{
		Implementor* m_pImp;
	public:
		Abstraction(Implementor* pImp) :m_pImp(pImp){}
		virtual ~Abstraction()
		{
			if (m_pImp)
				delete m_pImp;
			m_pImp = nullptr;
		}

		//自身的行为和属性
		virtual void request()
		{
			m_pImp->doSomething();
		}

		//获得实现化角色
		virtual Implementor* getImp()
		{
			return m_pImp;
		}
	};

	//RefinedAbstraction——修正抽象化角色
	//具体实现化角色
	class RefindAbstraction : public Abstraction
	{
	public:
		RefindAbstraction(Implementor* pImp) :Abstraction(pImp){}
		//修正父类的行为
		virtual void request() override
		{
			Abstraction::request();
			getImp()->doAnything();
		}
	};
}