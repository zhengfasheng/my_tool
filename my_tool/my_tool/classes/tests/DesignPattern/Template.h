#pragma once

//模板方法
//定义一个操作中的算法的框架， 而将一些步骤延迟到子类中。 使得子类可以不改
//变一个算法的结构即可重定义该算法的某些特定步骤。
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
		//是否有第一步操作
		virtual bool isOne()
		{
			return true;
		}
		//模板方法
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

		//重写
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
