#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
//备忘录模式

在不破坏封装性的前提下， 捕获一个对象的内部状
态， 并在该对象之外保存这个状态。 这样以后就可将该对象恢复到原先保存的状态。

● Originator发起人角色
记录当前时刻的内部状态， 负责定义哪些属于备份范围的状态， 负责创建和恢复备忘录
数据。
● Memento备忘录角色
负责存储Originator发起人对象的内部状态， 在需要的时候提供发起人需要的内部状态。
● Caretaker备忘录管理员角色
对备忘录进行管理、 保存和提供备忘录。

以现在的World为例，
World为定时的保存当前所编辑的文档
在一些特殊的情况下，如果World软件故障或其它的问题
还没来得及保存，这时下次在打开时
World会提示一个恢复功能，恢复到最近的保存点

*/

namespace MementoEx
{
	//Originator
	class Caretaker;
	class World
	{
	private:
		string m_content;//当前正在编辑的内容
		Caretaker* m_pCaretaker;//文档的备忘管理者
	public:
		World() :m_content(""),m_pCaretaker(nullptr){}
		~World();
		
		//得到当前编辑的内容，即当前的状态
		string getContent() const
		{
			return m_content;
		}

		void setContent( string content )
		{
			m_content = content;
		}

		void display()
		{
			cout << m_content << endl;
		}

		void createMemento();

		bool restoreMemento(size_t id);

		void displayAllMemento();

	};

	//Memento备忘录角色
	class Memento
	{
	private:
		string m_content;//备忘内容
	public:
		Memento( string content) :m_content(content){}

		string getContent()
		{
			return m_content;
		}
	};

	//Caretaker备忘录管理员角色
	class Caretaker
	{
	private:
		static size_t m_id;
		map<int, Memento*> m_pMemento;
	public:
		void addMemento(Memento* pMemento)
		{
			m_pMemento[Caretaker::m_id++] = pMemento;
		}

		Memento* getMemento(size_t id)
		{
			auto it = m_pMemento.find(id);
			if (it != m_pMemento.end())
			{
				return it->second;
			}
			return nullptr;
		}

		void display()
		{
			for (auto it = m_pMemento.begin(); it != m_pMemento.end(); ++it )
			{
				if (it->second)
				{
					cout << "id:" << it->first << " , content:" << it->second->getContent() << endl;
				}
			}
		}
	};

}