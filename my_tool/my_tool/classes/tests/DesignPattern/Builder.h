#pragma once
//将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
/*
1 builder：为创建一个产品对象的各个部件指定抽象接口。

2 ConcreteBuilder：实现Builder的接口以构造和装配该产品的各个部件，定义并明确它所创建的表示，并 提供一个检索产品的接口。

3 Director：构造一个使用Builder接口的对象。

4 Product：表示被构造的复杂对象。ConcreteBuilder创建该产品的内部表示并定义它的装配过程，包含定义组成部件的类，包括将这些部件装配成最终产品的接口。
*/

#include <string>
#include <iostream>
using namespace std;
namespace Builder
{
	//Product
	class Person
	{

	private:
		string head;
		string body;
		string foot;
	public:

		void setHead(string head)
		{
			this->head = head;
		}
		string getHead()
		{
			return head;
		}
		void setBody(string body)
		{
			this->body = body;
		}
		string getBody()
		{
			return this->body;
		}
		void setFoot(string foot)
		{
			this->foot = foot;
		}

		string getFoot()
		{
			return this->foot;
		}

		void display()
		{
			cout << "身体：" << this->body << endl;
			cout << "头：" << this->head << endl;
			cout << "脚：" << this->foot << endl;
		}
	};

	//builder
	class IPersonBuilder
	{
	public:
		IPersonBuilder(){};
		virtual ~IPersonBuilder(){}
	public:
		virtual void buildBody() = 0;
		virtual void buildHead() = 0;
		virtual void buildFoot() = 0;
	public:
		virtual Person* getPerson() = 0;
	};

	//ConcreteBuilder //男人 
	class MalePersonBuilder :
		public IPersonBuilder
	{
		Person* m_pPerson;
	public:
		MalePersonBuilder()
		{
			m_pPerson = new Person;
		}
		~MalePersonBuilder()
		{
			if (m_pPerson)
				delete m_pPerson;
			m_pPerson = nullptr;
		}

		virtual void buildBody() override
		{
			if ( m_pPerson )
			{
				m_pPerson->setBody("男人的身体");
			}
		}
		virtual void buildHead() override
		{
			if ( m_pPerson )
			{
				m_pPerson->setHead("男人的头");
			}
		}
		virtual void buildFoot() override
		{
			if ( m_pPerson )
			{
				m_pPerson->setFoot("男人的脚");
			}
		}
		virtual Person* getPerson() override
		{
			return m_pPerson;
		}
	};

	//ConcreteBuilder //女人
	class FemalePersonBuilder :
		public IPersonBuilder
	{
		Person* m_pPerson;
	public:
		FemalePersonBuilder()
		{
			m_pPerson = new Person;
		}
		~FemalePersonBuilder()
		{
			if (m_pPerson)
				delete m_pPerson;
			m_pPerson = nullptr;
		}

		virtual void buildBody() override
		{
			if (m_pPerson)
			{
				m_pPerson->setBody("女人的身体");
			}
		}
		virtual void buildHead() override
		{
			if (m_pPerson)
			{
				m_pPerson->setHead("女人的头");
			}
		}
		virtual void buildFoot() override
		{
			if (m_pPerson)
			{
				m_pPerson->setFoot("女人的脚");
			}
		}
		virtual Person* getPerson() override
		{
			return m_pPerson;
		}
	};

	//Director
	class PersonDirector
	{
	public:
		Person* builderPerson( IPersonBuilder * pBuilder )
		{
			if ( pBuilder == nullptr)
			{
				return nullptr;
			}
			pBuilder->buildBody();
			pBuilder->buildHead();
			pBuilder->buildFoot();
			return pBuilder->getPerson();
		}
	};

	//女人这里不写了(意思一下就行了)

}
