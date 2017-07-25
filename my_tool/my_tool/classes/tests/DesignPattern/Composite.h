#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
/*
组合模式，将对象组合成树形结构以表示“部分-整体”的层次结构，
组合模式使得用户对单个对象和组合对象的使用具有一致性。
掌握组合模式的重点是要理解清楚 “部分/整体”
还有 ”单个对象“ 与 "组合对象" 的含义。

组合模式可以让客户端像修改配置文件一样
简单的完成本来需要流程控制语句来完成的功能。

经典案例：系统目录结构，网站导航结构等。


涉及角色：

1.Component 
是组合中的对象声明接口，在适当的情况下，
实现所有类共有接口的默认行为。
声明一个接口用于访问和管理Component子部件。

2.Leaf 
在组合中表示叶子结点对象，叶子结点没有子结点。

3.Composite 
定义有枝节点行为，用来存储子部件，
在Component接口中实现与子部件有关操作，
如增加(add)和删除(remove)等。

下面有界面UI为例
*/

namespace Composite
{
	class Pool;
	//共同接口
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

	//Leaf//菜单项
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

	//Composite//菜单
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