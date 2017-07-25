#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
�Ž�/����ģʽ
�������ʵ�ֽ�� ʹ�����߿��Զ����ر仯��

�� Abstraction�������󻯽�ɫ
������Ҫְ���Ƕ�����ý�ɫ����Ϊ�� ͬʱ����һ����ʵ�ֻ���ɫ�����ã� �ý�ɫһ��
�ǳ����ࡣ
�� Implementor����ʵ�ֻ���ɫ
���ǽӿڻ��߳����࣬ �����ɫ�������Ϊ�����ԡ�
�� RefinedAbstraction�����������󻯽�ɫ
������ʵ�ֻ���ɫ�Գ��󻯽�ɫ����������
�� ConcreteImplementor��������ʵ�ֻ���ɫ
��ʵ�ֽӿڻ�����ඨ��ķ��������ԡ�


*/

namespace Bridge
{
	//Implementor����ʵ�ֻ���ɫ
	class Implementor
	{
	public:
		Implementor(){}
		virtual ~Implementor(){}
		virtual void doSomething() = 0;
		virtual void doAnything() = 0;
	};

	//ConcreteImplementor��������ʵ�ֻ���ɫ
	class ImplementorOne : public Implementor
	{
	public:
		~ImplementorOne()
		{
			cout << "~ImplementorOne()" << endl;
		}
		virtual void doSomething() override
		{
			cout << "ImplementorOne do something\n";
		}
		virtual void doAnything() override
		{
			cout << "ImplementorOne do anything\n";
		}
	};

	class ImplementorTwo : public Implementor
	{
	public:
		virtual void doSomething() override
		{
			cout << "ImplementorTwo do something\n";
		}
		virtual void doAnything() override
		{
			cout << "ImplementorTwo do anything\n";
		}
	};

	//Abstraction�������󻯽�ɫ
	class Abstraction
	{
		Implementor* m_pImp;
	public:
		Abstraction(Implementor* pImp) :m_pImp(pImp){}
		virtual ~Abstraction()
		{
			if (m_pImp)
				delete m_pImp;
			m_pImp = nullptr;
		}

		//�������Ϊ������
		virtual void request()
		{
			m_pImp->doSomething();
		}

		//���ʵ�ֻ���ɫ
		virtual Implementor* getImp()
		{
			return m_pImp;
		}
	};

	//RefinedAbstraction�����������󻯽�ɫ
	//����ʵ�ֻ���ɫ
	class RefindAbstraction : public Abstraction
	{
	public:
		RefindAbstraction(Implementor* pImp) :Abstraction(pImp){}
		//�����������Ϊ
		virtual void request() override
		{
			Abstraction::request();
			getImp()->doAnything();
		}
	};
}