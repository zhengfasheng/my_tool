#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
装饰者
动态地给一个对象添加一些额外的职责。就增加功能来说， Decorator模式相比生成子类
更为灵活。

参与者
• Component
— 定义一个对象接口，可以给这些对象动态地添加职责。
• ConcreteComponent
— 定义一个对象，可以给这个对象添加一些职责。
• Decorator
— 维持一个指向Component对象的指针，并定义一个与 Component接口一致的接口。
• ConcreteDecorator
— 向组件添加职责。
*/
namespace Decorator{

	//饮料Component
	class Beverage
	{
	protected:
		string m_description = "Unknown Beverage";
	public:
		Beverage( string desc ): m_description(desc){}
		virtual ~Beverage(){
			cout << "~Beverage()" << endl;
		}

		//饮料的描述
		virtual string getDescription() {
			return m_description;
		}
		//价格
		virtual double cost() = 0;

		void display() 
		{
			cout << getDescription() + " $" << cost() << endl;
		}
	};

	//浓咖啡ConcreteComponent
	class Espresso : public Beverage
	{
	public:
		Espresso() :Beverage("Espresso"){}
		virtual ~Espresso(){}
		virtual double cost() override
		{
			return 1.99;
		}
	};

	//黑咖啡ConcreteComponent
	class HouseBlend : public Beverage
	{
	public:
		HouseBlend() :Beverage("House Blend"){}
		~HouseBlend(){}
		virtual double cost() override
		{
			return .89;
		}
	};

	//调料Decorator
	class CondimentDecoator : public Beverage
	{
	public:
		CondimentDecoator(string desc) :Beverage(desc){}
		virtual ~CondimentDecoator(){}
	};

	//摩卡咖啡/优先咖啡ConcreteDecorator
	class Mocha : public CondimentDecoator
	{
	protected:
		//用一个实例变量记录饮料，也就是补装饰者
		Beverage* m_beverage;
	public:
		Mocha(Beverage* pBeverage) :CondimentDecoator(pBeverage->getDescription())
		{
			m_beverage = pBeverage;
		}
		~Mocha()
		{
			if (m_beverage)
				delete m_beverage;
			m_beverage = nullptr;
		}

		virtual string getDescription() override
		{
			return m_beverage->getDescription() + ",Mocha";
		}
		virtual double cost() override
		{
			return .20 + m_beverage->cost();
		}
	};

	//奶油ConcreteDecorator
	class Whip : public CondimentDecoator 
	{
	protected:
		Beverage* m_pBeverage;
	public:
		Whip(Beverage* pBeverage) :CondimentDecoator(pBeverage->getDescription())
		{
			m_pBeverage = pBeverage;
		}
		~Whip()
		{
			if (m_pBeverage)
				delete m_pBeverage;
			m_pBeverage = nullptr;
		}
		virtual string getDescription() override
		{
			return m_pBeverage->getDescription() + ",Whip";
		}
		virtual double cost() override
		{
			return .38 + m_pBeverage->cost();
		}
	};
}