#pragma  once

#include <iostream>
#include <string>
using namespace std;

/*

定义一系列的算法,把它们一个个封装起来 , 并且使它们可相互替换。本模式使得算法可独
立于使用它的客户而变化。

参与者
• Strategy(策略)
— 定义所有支持的算法的公共接口。 Context使用这个接口来调用某 ConcreteStrategy定
义的算法。
• ConcreteStrategy(具体策略)
— 以Strategy接口实现某具体算法。
• Context(上下文)
— 用一个ConcreteStrategy对象来配置。
— 维护一个对Strategy对象的引用。
— 可定义一个接口来让Strategy访问它的数据。

以出行旅游为例，可从车，可骑自行车等 
*/
namespace Strategy
{
	//Strategy
	class IStrategy
	{
	public:
		IStrategy(){}
		virtual ~IStrategy(){
			cout << "IStrategy" << endl;
		}

		virtual void travel() = 0;
	};

	//ConcreteStrategy
	//坐飞机
	class AirplaneStrategy : public IStrategy
	{
	public:
		virtual void travel() override
		{
			cout << "Travel by airplane" << endl;
		}
	};

	//从火车
	class TrainStrategy : public IStrategy
	{
	public:
		virtual void travel() override
		{
			cout << "Travel by train" << endl;
		}
	};

	//骑自行车
	class BicycleStrategy : public IStrategy
	{
	public:
		virtual void travel() override
		{
			cout << "Travel by bicycle" << endl;
		}
	};

	//Context
	class PersonContext
	{
		IStrategy* m_pStrategy;//旅游策略
	public:
		PersonContext(IStrategy* pStrategy) :m_pStrategy(pStrategy){}
		~PersonContext()
		{
			if (m_pStrategy)
				delete m_pStrategy;
			m_pStrategy = nullptr;
		}

		//更改旅行策略
		void changeTravelStrategy(IStrategy* pSrategy)
		{
			if (pSrategy == nullptr)
				return;
			if (m_pStrategy)
				delete m_pStrategy;
			m_pStrategy = pSrategy;
		}

		//旅游
		void travel()
		{
			if (m_pStrategy)
				m_pStrategy->travel();
		}
	};
}