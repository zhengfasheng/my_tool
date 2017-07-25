#pragma once
//用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从
//而使其耦合松散，而且可以独立地改变它们之间的交互。
/*
参与者
• Mediator(中介者)
— 中介者定义一个接口用于与各同事（Colleague）对象通信。
• ConcreteMediator(具体中介者)
— 具体中介者通过协调各同事对象实现协作行为。
— 了解并维护它的各个同事。
• Colleague class(同事类)
以租房为例子，如果没有房屋中介，那么房客要自己找房东，而房东也要自己找房客，
非常不方便。有了房屋中介机构就方便了，房东可以把要出租的房屋信息放到中介机构，
而房客可以去中介机构咨询。在软件中，就是多个对象之间需要通信，如果没有中介，
对象就需要知道其他对象，最坏情况下，可能需要知道所有其他对象，
而有了中介对象就方便多了，对象只需与中介对象通信，
而不用知道其他的对象。这就是中介者模式
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
namespace Mediator{

	class IMediator;

	class House;
	//Colleague抽象
	class Person
	{
	protected:
		string m_name;
		IMediator* m_mediator;//中介
		House* m_house;//住房
	public:
		Person(string name, IMediator* mediator, House* house = nullptr)
			:m_name(name),
			m_mediator(mediator),
			m_house(house)
		{
			
		}
		virtual ~Person();
		string getName()
		{
			return m_name;
		}
		House* getHouse()
		{
			return m_house;
		}
		void setHouse(House* p)
		{
			m_house = p;
		}
		IMediator* getMediator()
		{
			return m_mediator;
		}
		virtual void setMediator(IMediator* p) = 0;//设置中介
		virtual void lease(){}//向中介发送消息出租自己的房子
		virtual void rentByPrice(int price){}//从中介中得到房子信息(价格租房)
	};
	//房子
	class House
	{
	private:
		string m_position;//位置
		int m_size;//大小
		int m_price;//出租价格
		Person* m_houseOwner;//房主
	public:
		House(Person* houseOwner = nullptr, int size = 200 , int price = 1800 , string position = "宝安中心") :
			m_houseOwner(m_houseOwner),
			m_size(size),
			m_price(price),
			m_position(position)
		{
		}
		~House()
		{
			cout << "~House()" << endl;
			m_houseOwner = nullptr;
		}

		void setSize(int size){ m_size = size; }
		int getSize(){ return m_size; }

		void setPrice(int price);
		int getPrice() { return m_price; }

		void setPosition(string pos) { m_position = pos; }
		string getPosition() { return m_position; }

		void setOwner(Person* p){ m_houseOwner = p; }
		Person* getOwner() { return m_houseOwner; }

		void display()
		{
			cout << "-------------------------------" << endl;
			cout << "房主：" << m_houseOwner->getName() << endl;
			cout << "大小：" << m_size << "平米" << endl;
			cout << "位置：" << m_position << endl;
			cout << "价格：" << m_price << endl;
			cout << "-------------------------------" << endl;
			
		}

	};

	//抽象中介者
	class IMediator{
	public:
		IMediator(){}
		virtual ~IMediator(){}
		virtual void addHouseOwner(Person* p) = 0;//增加出租人（房主）
		virtual void addRenter(Person* p) = 0;//增加租房人(租客)
		virtual void show(House* house) = 0;//展示出租房
		virtual void show(int price) = 0;//展示出租房
	};

	//租客
	class Renter : public Person
	{
	public:
		Renter(string name, IMediator* mediator , House* house = nullptr ) :Person(name,mediator,house){}
		~Renter()
		{
			cout << "~Renter()" << endl;
		}
		virtual void setMediator(IMediator* p) override
		{
			m_mediator = p;
		}

		virtual void rentByPrice(int price) override
		{
			if ( m_mediator )
				m_mediator->show(price);
		}

	};

	//房东
	class Landlord : public Person
	{
	public:
		Landlord(string name, IMediator* mediator, House* house) : Person(name, mediator, house){}
		~Landlord()
		{
			cout << "~Landlord()" << endl;
		}
		virtual void setMediator(IMediator* p) override
		{
			m_mediator = p;
		}
		virtual void lease() override
		{
			if (m_mediator)
				m_mediator->show(m_house);
		}

	};

	

	//实例房屋中介
	class HouseMediator : public IMediator
	{
		vector<Person*> m_houseOwner;
		vector<Person*> m_renter;
	public:
		HouseMediator()
		{
			m_houseOwner.clear();
			m_renter.clear();
		}
		~HouseMediator()
		{
			
			for (auto it = m_houseOwner.begin(); it != m_houseOwner.end(); it++)
			{
				Person*& p = *it;
				if (p)
				{
					delete p;
					p = nullptr;
				}
			}
			for (auto it = m_renter.begin(); it != m_renter.end(); it++)
			{
				Person*& p = *it;
				if ( p )
				{
					delete p;
					p = nullptr;
				}
			}
			m_houseOwner.clear();
			m_renter.clear();
			cout << "~HouseMediator()" << endl;
		}

		virtual void addHouseOwner(Person* p) override
		{
			if (p)
			{
				m_houseOwner.push_back(p);
			}
		}

		virtual void addRenter(Person* p) override
		{
			if ( p )
			{
				m_renter.push_back(p);
			}
		}

		virtual void show(int price) override
		{
			cout << "价格为" << price << "元/月的房屋如下:" << endl;
			for ( Person*& p : m_houseOwner )
			{
				if (p && p->getHouse()->getPrice() == price )
				{
					p->getHouse()->display();
				}
			}

		}

		virtual void show(House* pHouse) override
		{
			if (pHouse == nullptr)
				return;
			cout << "出租房屋：" << endl;
			pHouse->display();
		}
		
	};
}