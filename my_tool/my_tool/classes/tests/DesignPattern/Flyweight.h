#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


/*
享元模式(flyweight)
使用共享对象可有效地支持大量的细
粒度的对象。

享元模式的定义为我们提出了两个要求： 细粒度的对象和共享对象。 我们知道分配太多
的对象到应用程序中将有损程序的性能， 同时还容易造成内存溢出， 那怎么避免呢？ 就是享
元模式提到的共享技术。 我们先来了解一下对象的内部状态和外部状态。

● Flyweight——抽象享元角色
它简单地说就是一个产品的抽象类， 同时定义出对象的外部状态和内部状态的接口或实
现。
● ConcreteFlyweight——具体享元角色
具体的一个产品类， 实现抽象角色定义的业务。 该角色中需要注意的是内部状态处理应
该与环境无关， 不应该出现一个操作改变了内部状态， 同时修改了外部状态， 这是绝对不允
许的。
● unsharedConcreteFlyweight——不可共享的享元角色
不存在外部状态或者安全要求（ 如线程安全） 不能够使用共享技术的对象， 该对象一般
不会出现在享元工厂中。
● FlyweightFactory——享元工厂
职责非常简单， 就是构造一个池容器， 同时提供从池中获得对象的方法。

*/

namespace Flyweight
{
	//Flyweight——抽象享元角色
	class IFlyweight
	{
	private:
		//内部状态
		string m_intrinsic;
		
	protected:
		//外部状态
		string m_extrinsic;

	public:
		IFlyweight(string extrinsic):m_extrinsic(extrinsic){}
		//定义业务操作
		virtual void operational() = 0;
		//内部状态的setter/getter
		virtual void setIntrinsic(string intrinsic)
		{
			m_intrinsic = intrinsic;
		}
		virtual string getIntrinsic()
		{
			return m_intrinsic;
		}
	};

	//● ConcreteFlyweight——具体享元角色

	class FlyweightObjectOne : public IFlyweight
	{
	public:
		FlyweightObjectOne(string extrinsic) :IFlyweight(extrinsic){}

		//具体实现业务处理逻辑
		virtual void operational() override
		{
			cout << "Flyweight object one operational" << endl;
		}
	};

	class FlyweightObjectTwo : public IFlyweight
	{
	public:
		FlyweightObjectTwo(string extrinsic) :IFlyweight(extrinsic){}

		//具体实现业务处理逻辑
		virtual void operational() override
		{
			cout << "Flyweight object two operational" << endl;
		}
	};

	//FlyweightFactory——享元工厂
	class FlyweightFactory
	{
	private:
		//数据池容器
		unordered_map<string, IFlyweight*> m_pool;
	private:
		FlyweightFactory(){}
	public:
		~FlyweightFactory()
		{
			release();
		}

		void release()
		{
			for (auto it = m_pool.begin(); it != m_pool.end();++it)
			{
				auto &p = it->second;
				if ( p )
				{
					delete p;
					p = nullptr;
				}
			}
			m_pool.clear();
		}
		//享元工厂间例
		static FlyweightFactory* getInstance()
		{
			static FlyweightFactory* pFactory = nullptr;
			if ( pFactory == nullptr )
			{
				pFactory = new FlyweightFactory;
			}
			return pFactory;
		}

		//通过外部状态得到对象
		template<class T>
		IFlyweight* getFlyweight(string extrinsic)
		{
			IFlyweight* p = nullptr;
			string key = typeid(T).name();
			key += extrinsic;
			auto it = m_pool.find(key);
			if ( it != m_pool.end() )//对象池中找到，直接返回
			{
				p =  it->second;
				cout << "从对象池中取出" << endl;
			}
			else
			{
				p = new T(key);
				cout << "创建了一个新的Flyweight对象" << endl;
				m_pool[key] = p;
			}
			return p;
		}
	};
}