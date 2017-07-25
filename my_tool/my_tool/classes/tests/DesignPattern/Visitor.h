#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
/*

访问者模式（ Visitor Pattern） 是一个相对简单的模式， 
其定义如下： Represent an
operation to be performed on the elements of an object structure. Visitor lets you define a new
operation without changing the classes of the elements on which it operates. 
（ 封装一些作用于某种
数据结构中的各元素的操作， 它可以在不改变数据结构的前提下定义作用于这些元素的新的
操作。 ）

● ConcreteVisitor——具体访问者
它影响访问者访问到一个类后该怎么干， 要做什么事情。
● Element——抽象元素
接口或者抽象类， 声明接受哪一类访问者访问， 程序上是通过accept方法中的参数来定
义的。
● ConcreteElement——具体元素
实现accept方法， 通常是visitor.visit(this)， 基本上都形成了一种模式了。
● ObjectStruture——结构对象
元素产生者， 一般容纳在多个不同类、 不同接口的容器， 如List、 Set、 Map等， 在项目
中， 一般很少抽象出这个角色。

*/

namespace visitor
{
	class IVisitor;
	//Element——抽象元素
	class Element
	{
	protected:
		IVisitor* m_pVisitor;
	public:
		Element():m_pVisitor(nullptr){}
		virtual ~Element();
		virtual void doSomthing() = 0;
		virtual void accept(IVisitor* pVisitor) = 0;
	};

	//ConcreteElement——具体元素
	class ElementOne : public Element
	{
	public:
		virtual void doSomthing() override
		{
			cout << "I'm an element one\n";
		}
		virtual void accept(IVisitor* pVisitor);
	};

	class ElementTwo : public Element
	{
	public:
		virtual void doSomthing() override
		{
			cout << "I'm an element two\n";
		}
		virtual void accept(IVisitor* pVisitor);
	};

	class ElementThree : public Element
	{
	public:
		virtual void doSomthing() override
		{
			cout << "I'm an element three\n";
		}
		virtual void accept(IVisitor* pVisitor);
	};

	//Visitor 访问者抽象
	class IVisitor
	{
	public:
		IVisitor(){}
		virtual ~IVisitor()
		{
			cout << "~IVisitor" << endl;
		}
		virtual void visit(ElementOne* p) = 0;
		virtual void visit(ElementTwo* p) = 0;
		virtual void visit(ElementThree* p) = 0;
	};

	//ConcreteVisitor——具体访问者
	class Visitor : public IVisitor
	{
	public:
		virtual void visit(ElementOne* p) override
		{
			if (p)
				p->doSomthing();
		}
		virtual void visit(ElementTwo* p) override
		{
			if (p)
				p->doSomthing();
		}
		virtual void visit(ElementThree* p) override
		{
			if (p)
				p->doSomthing();
		}
	};

	//ObjectStruture——结构对象
	class ObjectStruture
	{
		vector<Element*> m_elements;
		ObjectStruture(){}
	public:
		static ObjectStruture* getInstance()
		{
			static ObjectStruture* p = nullptr;
			if ( p == nullptr )
			{
				p = new ObjectStruture;
			}
			return p;
		}
		vector<Element*>& getElements()
		{
			default_random_engine dre;
			std::uniform_int_distribution<int> di(1,3);
			for (int i = 0; i < 10; i++ )
			{
				auto key = di(dre);
				if ( key == 1)
				{
					m_elements.push_back(new ElementOne);
				}
				else if (key == 2)
				{
					m_elements.push_back(new ElementTwo);
				}
				else
				{
					m_elements.push_back(new ElementThree);
				}
			}
			return m_elements;
		}

		void release()
		{
			for ( auto p : m_elements )
			{
				if ( p )
				{
					delete p;
					p = nullptr;
				}
			}
			m_elements.clear();
		}
	};
}