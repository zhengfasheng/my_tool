#pragma once
//��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
/*
1 builder��Ϊ����һ����Ʒ����ĸ�������ָ������ӿڡ�

2 ConcreteBuilder��ʵ��Builder�Ľӿ��Թ����װ��ò�Ʒ�ĸ������������岢��ȷ���������ı�ʾ���� �ṩһ��������Ʒ�Ľӿڡ�

3 Director������һ��ʹ��Builder�ӿڵĶ���

4 Product����ʾ������ĸ��Ӷ���ConcreteBuilder�����ò�Ʒ���ڲ���ʾ����������װ����̣�����������ɲ������࣬��������Щ����װ������ղ�Ʒ�Ľӿڡ�
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
			cout << "���壺" << this->body << endl;
			cout << "ͷ��" << this->head << endl;
			cout << "�ţ�" << this->foot << endl;
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

	//ConcreteBuilder //���� 
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
				m_pPerson->setBody("���˵�����");
			}
		}
		virtual void buildHead() override
		{
			if ( m_pPerson )
			{
				m_pPerson->setHead("���˵�ͷ");
			}
		}
		virtual void buildFoot() override
		{
			if ( m_pPerson )
			{
				m_pPerson->setFoot("���˵Ľ�");
			}
		}
		virtual Person* getPerson() override
		{
			return m_pPerson;
		}
	};

	//ConcreteBuilder //Ů��
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
				m_pPerson->setBody("Ů�˵�����");
			}
		}
		virtual void buildHead() override
		{
			if (m_pPerson)
			{
				m_pPerson->setHead("Ů�˵�ͷ");
			}
		}
		virtual void buildFoot() override
		{
			if (m_pPerson)
			{
				m_pPerson->setFoot("Ů�˵Ľ�");
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

	//Ů�����ﲻд��(��˼һ�¾�����)

}
