#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;

/*
�۲���ģʽ
���������һ��һ�Զ��������ϵ ,
��һ�������״̬�����ı�ʱ , �������������Ķ���
���õ�֪ͨ�����Զ����¡�

�� Subject���۲���
���屻�۲��߱���ʵ�ֵ�ְ�� �������ܹ���̬�����ӡ� ȡ���۲��ߡ� ��һ���ǳ�����
������ʵ���࣬ ���������Ϊ���۲��߱���ʵ�ֵ�ְ�� ����۲��߲�֪ͨ�۲��ߡ�
�� Observer�۲���
�۲��߽��յ���Ϣ�� ������update�� ���·����� ������ �Խ��յ�����Ϣ���д���
�� ConcreteSubject����ı��۲���
���屻�۲����Լ���ҵ���߼��� ͬʱ�������Щ�¼�����֪ͨ��
�� ConcreteObserver����Ĺ۲���
ÿ���۲��ڽ��յ���Ϣ��Ĵ���Ӧ�ǲ�ͬ�� �����۲������Լ��Ĵ����߼���

�۲���ģʽ  ������+������=�۲���ģʽ

���±ߵ�ͼ��˵����    �����ձ�+������=�۲���ģʽ


*/
namespace Observer
{
	class ISubscriber;
	//Subject���۲���
	class INewsPaper
	{
	public:
		INewsPaper() {}
		virtual ~INewsPaper(){}

		//��Ӷ�����
		virtual void addSubscriber(ISubscriber* p) = 0;

		//ɾ��������
		virtual void removeSubscriber(ISubscriber* p) = 0;

		//���ͱ�ֽ
		virtual void sendPaper() = 0;

		//��������
		virtual string getName() = 0;
	};

	//Observer�۲���
	class ISubscriber
	{
	public:
		ISubscriber(){}
		virtual ~ISubscriber(){}
		//���µı�ֽ֪ͨ
		virtual void hasNewPaper( INewsPaper* p ) = 0;
		//����������
		virtual string getName() = 0;
	};

	//ConcreteSubject����ı��۲���

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
				cout << p->getName() << "ͬѧ�����Ѿ����Ĺ���" << endl;
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

			cout << "-------------���ͱ�ֽ���------------" << endl;
		}

	};
	//�����ձ�
	class PeopleDaily : public Newspaper
	{
	public:
		PeopleDaily(){}
		~PeopleDaily()
		{
			
		}
		virtual string getName() override
		{
			return "�����ձ�";
		}
	};

	//�����ձ�
	class GuangmingDaily : public Newspaper
	{
	public:
		GuangmingDaily(){}
		~GuangmingDaily(){}
		virtual string getName() override
		{
			return "�����ձ�";
		}

	};

	//ConcreteObserver����Ĺ۲���
	//���ı�ֽ����
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
			cout << m_name << "ͬѧ,�����ĵ�<<" << p->getName() << ">>���±�ֽ�ˣ������" << endl;
		}

		virtual string getName() override
		{
			return m_name; 
		}
	};

}