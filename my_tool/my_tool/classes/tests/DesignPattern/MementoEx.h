#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
/*
//����¼ģʽ

�ڲ��ƻ���װ�Ե�ǰ���£� ����һ��������ڲ�״
̬�� ���ڸö���֮�Ᵽ�����״̬�� �����Ժ�Ϳɽ��ö���ָ���ԭ�ȱ����״̬��

�� Originator�����˽�ɫ
��¼��ǰʱ�̵��ڲ�״̬�� ��������Щ���ڱ��ݷ�Χ��״̬�� ���𴴽��ͻָ�����¼
���ݡ�
�� Memento����¼��ɫ
����洢Originator�����˶�����ڲ�״̬�� ����Ҫ��ʱ���ṩ��������Ҫ���ڲ�״̬��
�� Caretaker����¼����Ա��ɫ
�Ա���¼���й��� ������ṩ����¼��

�����ڵ�WorldΪ����
WorldΪ��ʱ�ı��浱ǰ���༭���ĵ�
��һЩ���������£����World������ϻ�����������
��û���ü����棬��ʱ�´��ڴ�ʱ
World����ʾһ���ָ����ܣ��ָ�������ı����

*/

namespace MementoEx
{
	//Originator
	class Caretaker;
	class World
	{
	private:
		string m_content;//��ǰ���ڱ༭������
		Caretaker* m_pCaretaker;//�ĵ��ı���������
	public:
		World() :m_content(""),m_pCaretaker(nullptr){}
		~World();
		
		//�õ���ǰ�༭�����ݣ�����ǰ��״̬
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

	//Memento����¼��ɫ
	class Memento
	{
	private:
		string m_content;//��������
	public:
		Memento( string content) :m_content(content){}

		string getContent()
		{
			return m_content;
		}
	};

	//Caretaker����¼����Ա��ɫ
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