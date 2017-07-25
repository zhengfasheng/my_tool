#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


/*
��Ԫģʽ(flyweight)
ʹ�ù���������Ч��֧�ִ�����ϸ
���ȵĶ���

��Ԫģʽ�Ķ���Ϊ�������������Ҫ�� ϸ���ȵĶ���͹������ ����֪������̫��
�Ķ���Ӧ�ó����н������������ܣ� ͬʱ����������ڴ������ ����ô�����أ� ������
Ԫģʽ�ᵽ�Ĺ������� ���������˽�һ�¶�����ڲ�״̬���ⲿ״̬��

�� Flyweight����������Ԫ��ɫ
���򵥵�˵����һ����Ʒ�ĳ����࣬ ͬʱ�����������ⲿ״̬���ڲ�״̬�Ľӿڻ�ʵ
�֡�
�� ConcreteFlyweight����������Ԫ��ɫ
�����һ����Ʒ�࣬ ʵ�ֳ����ɫ�����ҵ�� �ý�ɫ����Ҫע������ڲ�״̬����Ӧ
���뻷���޹أ� ��Ӧ�ó���һ�������ı����ڲ�״̬�� ͬʱ�޸����ⲿ״̬�� ���Ǿ��Բ���
��ġ�
�� unsharedConcreteFlyweight�������ɹ������Ԫ��ɫ
�������ⲿ״̬���߰�ȫҪ�� ���̰߳�ȫ�� ���ܹ�ʹ�ù������Ķ��� �ö���һ��
�����������Ԫ�����С�
�� FlyweightFactory������Ԫ����
ְ��ǳ��򵥣� ���ǹ���һ���������� ͬʱ�ṩ�ӳ��л�ö���ķ�����

*/

namespace Flyweight
{
	//Flyweight����������Ԫ��ɫ
	class IFlyweight
	{
	private:
		//�ڲ�״̬
		string m_intrinsic;
		
	protected:
		//�ⲿ״̬
		string m_extrinsic;

	public:
		IFlyweight(string extrinsic):m_extrinsic(extrinsic){}
		//����ҵ�����
		virtual void operational() = 0;
		//�ڲ�״̬��setter/getter
		virtual void setIntrinsic(string intrinsic)
		{
			m_intrinsic = intrinsic;
		}
		virtual string getIntrinsic()
		{
			return m_intrinsic;
		}
	};

	//�� ConcreteFlyweight����������Ԫ��ɫ

	class FlyweightObjectOne : public IFlyweight
	{
	public:
		FlyweightObjectOne(string extrinsic) :IFlyweight(extrinsic){}

		//����ʵ��ҵ�����߼�
		virtual void operational() override
		{
			cout << "Flyweight object one operational" << endl;
		}
	};

	class FlyweightObjectTwo : public IFlyweight
	{
	public:
		FlyweightObjectTwo(string extrinsic) :IFlyweight(extrinsic){}

		//����ʵ��ҵ�����߼�
		virtual void operational() override
		{
			cout << "Flyweight object two operational" << endl;
		}
	};

	//FlyweightFactory������Ԫ����
	class FlyweightFactory
	{
	private:
		//���ݳ�����
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
		//��Ԫ��������
		static FlyweightFactory* getInstance()
		{
			static FlyweightFactory* pFactory = nullptr;
			if ( pFactory == nullptr )
			{
				pFactory = new FlyweightFactory;
			}
			return pFactory;
		}

		//ͨ���ⲿ״̬�õ�����
		template<class T>
		IFlyweight* getFlyweight(string extrinsic)
		{
			IFlyweight* p = nullptr;
			string key = typeid(T).name();
			key += extrinsic;
			auto it = m_pool.find(key);
			if ( it != m_pool.end() )//��������ҵ���ֱ�ӷ���
			{
				p =  it->second;
				cout << "�Ӷ������ȡ��" << endl;
			}
			else
			{
				p = new T(key);
				cout << "������һ���µ�Flyweight����" << endl;
				m_pool[key] = p;
			}
			return p;
		}
	};
}