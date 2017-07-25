#pragma once

//ģ�巽��
//����һ�������е��㷨�Ŀ�ܣ� ����һЩ�����ӳٵ������С� ʹ��������Բ���
//��һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض����衣
#include <iostream>
using namespace std;
namespace Template
{
	class IClass 
	{
	public:
		IClass(){}
		virtual ~IClass(){}
	protected:
		virtual void operationOne() = 0;
		virtual void operationTwo() = 0;
		//�Ƿ��е�һ������
		virtual bool isOne()
		{
			return true;
		}
		//ģ�巽��
	public:
		void operation()
		{
			if ( isOne() )
			{
				operationOne();
			}
			
			operationTwo();
		}
	};

	class ConcreteOne :
		public IClass
	{
	protected:
		virtual void operationOne() override
		{
			cout << "ConcreteOne operationOne" << endl;
		}
		virtual void operationTwo() override
		{
			cout << "ConcreteOne operationTwo" << endl;
		}

		//��д
		virtual bool isOne() override
		{
			return false;
		}
	};

	class ConcreteTwo :
		public IClass
	{
	protected:
		virtual void operationOne() override
		{
			cout << "ConcreteTwo operationOne" << endl;
		}
		virtual void operationTwo() override
		{
			cout << "ConcreteTwo operationTwo" << endl;
		}
	};
}
