#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
迭代器模式（ Iterator Pattern） 目前已经是一个没落的模式， 基本上没人会单独写一个迭
代器， 除非是产品性质的开发， 其定义如下：
它提供一种方法访问一个容器对象中各个元素， 而又不需暴露该
对象的内部细节。

● Iterator抽象迭代器
抽象迭代器负责定义访问和遍历元素的接口， 而且基本上是有固定的3个方法： first()获
得第一个元素， next()访问下一个元素， isDone()是否已经访问到底部（ Java叫做hasNext()方
法） 。
● ConcreteIterator具体迭代器
具体迭代器角色要实现迭代器接口， 完成容器元素的遍历。
● Aggregate抽象容器
容器角色负责提供创建具体迭代器角色的接口， 必然提供一个类似createIterator()这样的
方法， 在Java中一般是iterator()方法。
● Concrete Aggregate具体容器
具体容器实现容器接口定义的方法， 创建出容纳迭代器的对象。


下面以服务生给客人菜单为列

*/

namespace SimpleIterator
{

	//菜单项
	class MenuItem
	{
	private:
		string m_name; //菜名
		string m_description;//描述
		double m_price;//价格
	public:
		MenuItem(string name, string desc, double price)
			:m_name(name), m_description(desc), m_price(price){}

		void display() const
		{
			cout << m_name << "\t" << m_description << "\t" << m_price << endl;
		}
	};

	//Iterator
	class myiterator 
	{
	public:
		myiterator(){}
		virtual ~myiterator(){}
		virtual bool hasNext() = 0;
		virtual MenuItem next() = 0;
	};

	//ConcreteIterator具体迭代器
	class readIterator : public myiterator
	{
		size_t m_cursor;
		std::vector<MenuItem> m_vector;
	public:
		readIterator(std::vector<MenuItem>& vec) :m_vector(vec),m_cursor(0){}
		~readIterator(){ m_vector.clear(); };

		virtual bool hasNext() override
		{
			if (m_cursor == m_vector.size())
				return false;
			return true;
		}

		virtual MenuItem next() override
		{
			MenuItem result = MenuItem("","",0);
			if (hasNext())
				result = m_vector[m_cursor++];
			return result;
		}

	};


	//Aggregate抽象容器
	//菜单
	class Menu
	{
	public:
		Menu(){}
		virtual ~Menu(){}
		virtual myiterator* createIterator() = 0;
	};

	//Concrete Aggregate具体容器
	//小吃
	class SnackMenu : public Menu
	{
	protected:
		vector<MenuItem> m_vector;
	public:
		SnackMenu()
		{
			m_vector.push_back(MenuItem("砂锅饭", "小吃", 15));
			m_vector.push_back(MenuItem("冒菜", "小吃", 13));
			m_vector.push_back(MenuItem("烧烤", "小吃", 11));
		}
		~SnackMenu()
		{
			m_vector.clear();
		}

		virtual myiterator* createIterator() override
		{
			return new readIterator(m_vector);
		}
	};

	//主饭
	class DinnerMenu : public Menu
	{
	protected:
		vector<MenuItem> m_vector;
	public:
		DinnerMenu()
		{
			m_vector.push_back(MenuItem("青岛大虾", "主食", 200));
			m_vector.push_back(MenuItem("红烧肉", "主食", 20));
			m_vector.push_back(MenuItem("土豆排骨", "主食", 18));
		}
		~DinnerMenu()
		{
			m_vector.clear();
		}

		virtual myiterator* createIterator() override
		{
			return new readIterator(m_vector);
		}
	};

	//服务生
	class Waitress
	{
		Menu* m_pSnackMenu;
		Menu* m_pDinerMenu;
	public:
		Waitress()
		{
			m_pDinerMenu = new DinnerMenu;
			m_pSnackMenu = new SnackMenu;
		}
		~Waitress()
		{
			if (m_pDinerMenu)
				delete m_pDinerMenu;
			if (m_pSnackMenu)
				delete m_pSnackMenu;
			m_pSnackMenu = nullptr;
			m_pDinerMenu = nullptr;
		}

		void printMenu()
		{
			auto itSnack = m_pSnackMenu->createIterator();
			printMenu(itSnack);
			auto itDiner = m_pDinerMenu->createIterator();
			printMenu(itDiner);
		}

		
		void printMenu(myiterator* it)
		{
			while ( it->hasNext() )
			{
				it->next().display();
			}
		}
	};

}