#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
/*
���ģʽ����������ϳ����νṹ�Ա�ʾ������-���塱�Ĳ�νṹ��
���ģʽʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�
�������ģʽ���ص���Ҫ������ ������/���塱
���� ���������� �� "��϶���" �ĺ��塣

���ģʽ�����ÿͻ������޸������ļ�һ��
�򵥵���ɱ�����Ҫ���̿����������ɵĹ��ܡ�

���䰸����ϵͳĿ¼�ṹ����վ�����ṹ�ȡ�


�漰��ɫ��

1.Component 
������еĶ��������ӿڣ����ʵ�������£�
ʵ�������๲�нӿڵ�Ĭ����Ϊ��
����һ���ӿ����ڷ��ʺ͹���Component�Ӳ�����

2.Leaf 
������б�ʾҶ�ӽ�����Ҷ�ӽ��û���ӽ�㡣

3.Composite 
������֦�ڵ���Ϊ�������洢�Ӳ�����
��Component�ӿ���ʵ�����Ӳ����йز�����
������(add)��ɾ��(remove)�ȡ�

�����н���UIΪ��
*/

namespace Composite
{
	class Pool;
	//��ͬ�ӿ�
	class Ref
	{
	protected:
		size_t m_useCount;
		Ref* m_parent;
	public:
		Ref():m_useCount(1),m_parent(nullptr){}
		virtual ~Ref() {
			cout << "~Ref()" << endl;
			m_parent = nullptr;
		}
		void release();
		void retain();
		void autorelease();
		virtual string getName() const = 0;
		int getUseCount()
		{
			return m_useCount;
		}
		virtual void display( )
		{
			cout << getName() << endl;
		}
		virtual void setParent(Ref* pParent)
		{
			m_parent = pParent;
		}

		virtual Ref* getParent() const
		{
			return m_parent;
		}
	};

	class Pool : public Ref
	{
		vector<Ref*> m_children;
	public:
		Pool(){}
		void addChild(Ref* pChild);

		virtual string getName() const;
	public:
		static Pool* getInstance();

		void tick();
	};

	//Component
	class Component : public Ref
	{
	protected:
		string m_name;
		vector<Ref*> m_children;
	public:
		Component( string name ):m_name(name){}
		virtual ~Component(){
			for ( auto p : m_children )
			{
				if (p)
					p->release();
				p = nullptr;
			}
			m_children.clear();
		}
		virtual void addChild(Ref* pChild)
		{
			if (pChild == nullptr) return;
			m_children.push_back(pChild);
			pChild->setParent(this);
			pChild->retain();
		}
		virtual void removeChild(Ref* pChild)
		{
			auto it = find(m_children.begin(), m_children.end(), pChild);
			if ( it != m_children.end() )
			{
				(*it)->release();
				m_children.erase(it);
			}
		}
		virtual vector<Ref*>& getChildren()
		{
			return m_children;
		}
		virtual string getName() const
		{
			return m_name;
		}
		virtual void display( ) override
		{
			Ref::display();
		}
	};

	//Leaf//�˵���
	class MenuItem : public Ref
	{
		string m_name;
	public:
		MenuItem(string name) : m_name(name){}
		~MenuItem(){
			//cout << "~MenuItem()" << endl;
		}
		virtual string getName() const override
		{
			return m_name;
		}

		static MenuItem* create( string name )
		{
			auto p = new MenuItem(name);
			p->autorelease();
			return p;
		}

	};

	//Composite//�˵�
	class Menu : public Component
	{
	public:
		Menu(string name) :Component(name){}
		~Menu(){}
		static Menu* create(string name)
		{
			Menu* p = new Menu(name);
			p->autorelease();
			return p;
		}

		virtual void display( )override
		{
			Component::display();
			string str = "    ";
			size_t count = 0;
			for ( auto p : m_children )
			{
				if (p)
				{
					auto pParent = p->getParent();
					while (pParent)
					{
						cout << str;
						pParent = pParent->getParent();
					}
					p->display( );
				}
				
			}
		}

	};
}