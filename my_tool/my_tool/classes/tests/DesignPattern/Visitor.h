#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;
/*

������ģʽ�� Visitor Pattern�� ��һ����Լ򵥵�ģʽ�� 
�䶨�����£� Represent an
operation to be performed on the elements of an object structure. Visitor lets you define a new
operation without changing the classes of the elements on which it operates. 
�� ��װһЩ������ĳ��
���ݽṹ�еĸ�Ԫ�صĲ����� �������ڲ��ı����ݽṹ��ǰ���¶�����������ЩԪ�ص��µ�
������ ��

�� ConcreteVisitor�������������
��Ӱ������߷��ʵ�һ��������ô�ɣ� Ҫ��ʲô���顣
�� Element��������Ԫ��
�ӿڻ��߳����࣬ ����������һ������߷��ʣ� ��������ͨ��accept�����еĲ�������
��ġ�
�� ConcreteElement��������Ԫ��
ʵ��accept������ ͨ����visitor.visit(this)�� �����϶��γ���һ��ģʽ�ˡ�
�� ObjectStruture�����ṹ����
Ԫ�ز����ߣ� һ�������ڶ����ͬ�ࡢ ��ͬ�ӿڵ������� ��List�� Set�� Map�ȣ� ����Ŀ
�У� һ����ٳ���������ɫ��

*/

namespace visitor
{
	class IVisitor;
	//Element��������Ԫ��
	class Element
	{
	protected:
		IVisitor* m_pVisitor;
	public:
		Element():m_pVisitor(nullptr){}
		virtual ~Element();
		virtual void doSomthing() = 0;
		virtual void accept(IVisitor* pVisitor) = 0;
	};

	//ConcreteElement��������Ԫ��
	class ElementOne : public Element
	{
	public:
		virtual void doSomthing() override
		{
			cout << "I'm an element one\n";
		}
		virtual void accept(IVisitor* pVisitor);
	};

	class ElementTwo : public Element
	{
	public:
		virtual void doSomthing() override
		{
			cout << "I'm an element two\n";
		}
		virtual void accept(IVisitor* pVisitor);
	};

	class ElementThree : public Element
	{
	public:
		virtual void doSomthing() override
		{
			cout << "I'm an element three\n";
		}
		virtual void accept(IVisitor* pVisitor);
	};

	//Visitor �����߳���
	class IVisitor
	{
	public:
		IVisitor(){}
		virtual ~IVisitor()
		{
			cout << "~IVisitor" << endl;
		}
		virtual void visit(ElementOne* p) = 0;
		virtual void visit(ElementTwo* p) = 0;
		virtual void visit(ElementThree* p) = 0;
	};

	//ConcreteVisitor�������������
	class Visitor : public IVisitor
	{
	public:
		virtual void visit(ElementOne* p) override
		{
			if (p)
				p->doSomthing();
		}
		virtual void visit(ElementTwo* p) override
		{
			if (p)
				p->doSomthing();
		}
		virtual void visit(ElementThree* p) override
		{
			if (p)
				p->doSomthing();
		}
	};

	//ObjectStruture�����ṹ����
	class ObjectStruture
	{
		vector<Element*> m_elements;
		ObjectStruture(){}
	public:
		static ObjectStruture* getInstance()
		{
			static ObjectStruture* p = nullptr;
			if ( p == nullptr )
			{
				p = new ObjectStruture;
			}
			return p;
		}
		vector<Element*>& getElements()
		{
			default_random_engine dre;
			std::uniform_int_distribution<int> di(1,3);
			for (int i = 0; i < 10; i++ )
			{
				auto key = di(dre);
				if ( key == 1)
				{
					m_elements.push_back(new ElementOne);
				}
				else if (key == 2)
				{
					m_elements.push_back(new ElementTwo);
				}
				else
				{
					m_elements.push_back(new ElementThree);
				}
			}
			return m_elements;
		}

		void release()
		{
			for ( auto p : m_elements )
			{
				if ( p )
				{
					delete p;
					p = nullptr;
				}
			}
			m_elements.clear();
		}
	};
}