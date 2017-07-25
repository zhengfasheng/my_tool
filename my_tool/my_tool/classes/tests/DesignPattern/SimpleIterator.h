#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
������ģʽ�� Iterator Pattern�� Ŀǰ�Ѿ���һ��û���ģʽ�� ������û�˻ᵥ��дһ����
������ �����ǲ�Ʒ���ʵĿ����� �䶨�����£�
���ṩһ�ַ�������һ�����������и���Ԫ�أ� ���ֲ��豩¶��
������ڲ�ϸ�ڡ�

�� Iterator���������
�����������������ʺͱ���Ԫ�صĽӿڣ� ���һ��������й̶���3�������� first()��
�õ�һ��Ԫ�أ� next()������һ��Ԫ�أ� isDone()�Ƿ��Ѿ����ʵ��ײ��� Java����hasNext()��
���� ��
�� ConcreteIterator���������
�����������ɫҪʵ�ֵ������ӿڣ� �������Ԫ�صı�����
�� Aggregate��������
������ɫ�����ṩ���������������ɫ�Ľӿڣ� ��Ȼ�ṩһ������createIterator()������
������ ��Java��һ����iterator()������
�� Concrete Aggregate��������
��������ʵ�������ӿڶ���ķ����� ���������ɵ������Ķ���


�����Է����������˲˵�Ϊ��

*/

namespace SimpleIterator
{

	//�˵���
	class MenuItem
	{
	private:
		string m_name; //����
		string m_description;//����
		double m_price;//�۸�
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

	//ConcreteIterator���������
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


	//Aggregate��������
	//�˵�
	class Menu
	{
	public:
		Menu(){}
		virtual ~Menu(){}
		virtual myiterator* createIterator() = 0;
	};

	//Concrete Aggregate��������
	//С��
	class SnackMenu : public Menu
	{
	protected:
		vector<MenuItem> m_vector;
	public:
		SnackMenu()
		{
			m_vector.push_back(MenuItem("ɰ����", "С��", 15));
			m_vector.push_back(MenuItem("ð��", "С��", 13));
			m_vector.push_back(MenuItem("�տ�", "С��", 11));
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

	//����
	class DinnerMenu : public Menu
	{
	protected:
		vector<MenuItem> m_vector;
	public:
		DinnerMenu()
		{
			m_vector.push_back(MenuItem("�ൺ��Ϻ", "��ʳ", 200));
			m_vector.push_back(MenuItem("������", "��ʳ", 20));
			m_vector.push_back(MenuItem("�����Ź�", "��ʳ", 18));
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

	//������
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