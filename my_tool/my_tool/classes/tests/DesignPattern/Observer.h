#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
观察者模式
定义对象间的一种一对多的依赖关系 ,
当一个对象的状态发生改变时 , 所有依赖于它的对象
都得到通知并被自动更新。

● Subject被观察者
定义被观察者必须实现的职责， 它必须能够动态地增加、 取消观察者。 它一般是抽象类
或者是实现类， 仅仅完成作为被观察者必须实现的职责： 管理观察者并通知观察者。
● Observer观察者
观察者接收到消息后， 即进行update（ 更新方法） 操作， 对接收到的信息进行处理。
● ConcreteSubject具体的被观察者
定义被观察者自己的业务逻辑， 同时定义对哪些事件进行通知。
● ConcreteObserver具体的观察者
每个观察在接收到消息后的处理反应是不同， 各个观察者有自己的处理逻辑。

观察者模式  出版者+订阅者=观察者模式

用下边的图来说就是    人民日报+订阅者=观察者模式


*/
namespace Observer
{
	class ISubscriber;
	//Subject被观察者
	class INewsPaper
	{
	public:
		INewsPaper() {}
		virtual ~INewsPaper(){}

		//添加订阅者
		virtual void addSubscriber(ISubscriber* p) = 0;

		//删除订阅者
		virtual void removeSubscriber(ISubscriber* p) = 0;

		//发送报纸
		virtual void sendPaper() = 0;

		//报社名称
		virtual string getName() = 0;
	};

	//Observer观察者
	class ISubscriber
	{
	public:
		ISubscriber(){}
		virtual ~ISubscriber(){}
		//有新的报纸通知
		virtual void hasNewPaper( INewsPaper* p ) = 0;
		//订阅者名称
		virtual string getName() = 0;
	};

	//ConcreteSubject具体的被观察者

	class Newspaper : public INewsPaper
	{
		list<ISubscriber*> m_subcriber;
	public:
		Newspaper(){}
		virtual ~Newspaper()
		{
			while (m_subcriber.size() > 0)
			{
				/*auto p = m_subcriber.front();
				if (p)
				{
				delete p;
				p = nullptr;
				}*/
				m_subcriber.erase(m_subcriber.begin());
			}
		}

		virtual void addSubscriber(ISubscriber* p) override
		{
			auto it = find(m_subcriber.begin(), m_subcriber.end(), p);
			if ( it != m_subcriber.end() )
			{
				cout << p->getName() << "同学，您已经订阅过了" << endl;
				return;
			}
			m_subcriber.push_back(p);
		}

		virtual void removeSubscriber(ISubscriber* p) override
		{
			auto it = find(m_subcriber.begin(), m_subcriber.end(), p);
			if (it != m_subcriber.end())
			{
				/*delete *it;
				*it = nullptr;*/
				m_subcriber.erase(it);
			}
		}

		virtual void sendPaper() override
		{
			for (auto it = m_subcriber.begin(); it != m_subcriber.end(); ++it)
			{
				(*it)->hasNewPaper(this);
			}

			cout << "-------------发送报纸完毕------------" << endl;
		}

	};
	//人民日报
	class PeopleDaily : public Newspaper
	{
	public:
		PeopleDaily(){}
		~PeopleDaily()
		{
			
		}
		virtual string getName() override
		{
			return "人民日报";
		}
	};

	//光明日报
	class GuangmingDaily : public Newspaper
	{
	public:
		GuangmingDaily(){}
		~GuangmingDaily(){}
		virtual string getName() override
		{
			return "光明日报";
		}

	};

	//ConcreteObserver具体的观察者
	//订阅报纸的人
	class Subscriber : public ISubscriber
	{
		string m_name;
	public:
		Subscriber(string name) :m_name(name){}
		~Subscriber()
		{
			cout << "~Subscriber()" << endl;
		}

		virtual void hasNewPaper( INewsPaper* p ) override
		{
			cout << m_name << "同学,您订阅的<<" << p->getName() << ">>有新报纸了，请查收" << endl;
		}

		virtual string getName() override
		{
			return m_name; 
		}
	};

}