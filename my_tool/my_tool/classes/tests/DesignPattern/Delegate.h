#pragma once
//为其他对象提供一种代理以控制对这个对象的访问。
/*
• Proxy 
— 保存一个引用使得代理可以访问实体。若 RealSubject和Subject的接口相同，Proxy会
引用Subject。
— 提供一个与Subject的接口相同的接口，这样代理就可以用来替代实体。
— 控制对实体的存取，并可能负责创建和删除它。
• Subject
— 定义RealSubject 和Proxy的共用接口，这样就在任何使用 RealSubject的地方都可以使
用Proxy。
• RealSubject
— 定义Proxy所代表的实体。
*/
#include <iostream>
using namespace std;
namespace Delegate
{
	//Subject
	class Subject
	{
	public: 
		Subject(){}
		virtual ~Subject(){}
		virtual void request() = 0;
	};

	//RealSubject
	class RealSubject :
		public Subject
	{

	public:
		~RealSubject()
		{
			cout << "~RealSubject()" << endl;
		}
		virtual void request() override
		{
			cout << "real subject request" << endl;
		}
	};

	//Proxy 代理
	class Proxy :
		public Subject
	{
		Subject* m_pRealSubject;
	public:
		Proxy(Subject* pRealSubject):m_pRealSubject(pRealSubject){}
		~Proxy()
		{
			if ( m_pRealSubject )
			{
				delete m_pRealSubject;
				m_pRealSubject = nullptr;
			}
		}
	
		virtual void request() override
		{
			if (m_pRealSubject)
				m_pRealSubject->request();
		}
	};
}