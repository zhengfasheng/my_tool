#pragma once
#include <iostream>
using namespace std;
/*
很多对象由每一个对象对其下家的引用而连接起来形成一条链。
请求在这个链上传递，直到链上的某一个对象决定处理此请求。
发出这个请求的客户端并不知道链上的哪一个对象最终处理这个请求，
这使得系统可以在不影响客户端的情况下动态地重新组织和分配责任

责任链模式涉及到的角色如下所示：

●　抽象处理者(Handler)角色：
定义出一个处理请求的接口。如果需要，
接口可以定义 出一个方法以设定和返回对下家的引用。
这个角色通常由一个Java抽象类或者Java接口实现。
上图中Handler类的聚合关系给出了具体子类对下家的引用，
抽象方法handleRequest()规范了子类处理请求的操作。

●　具体处理者(ConcreteHandler)角色：
具体处理者接到请求后，可以选择将请求处理掉，
或者将请求传给下家。由于具体处理者持有对下家的引用，
因此，如果需要，具体处理者可以访问下家。


中国古代对妇女制定了“三从四德”的道德规范， “三从”是指“未嫁从父、 既嫁从夫、 夫
死从子”。 也就是说， 一位女性在结婚之前要听从于父亲， 结婚之后要听从于丈夫， 如果丈
夫死了还要听从于儿子。 举例来说， 如果一位女性要出去逛街， 在她出嫁前必须征得父亲的
同意， 出嫁之后必须获得丈夫的许可， 那丈夫死了怎么办？ 那就得问问儿子是否允许自己出
去逛街。 估计你接下来马上要问： “要是没有儿子怎么办？ ”那就请示小叔子、 侄子等。 在父
系社会中， 妇女只占从属地位， 现在想想中国古代的妇女还是挺悲惨的， 连逛街都要多番请
示。 作为父亲、 丈夫或儿子， 只有两种选择： 要不承担起责任来， 允许她或不允许她逛街；
要不就让她请示下一个人， 这是整个社会体系的约束， 应用到我们项目中就是业务规则。 下
面来看如何通过程序来实现“三从”，
*/

#include <iostream>
#include <string>
using namespace std;
namespace Responsibility
{
	enum Type
	{
		Girl,//未出嫁
		Wife,//出嫁
		Widow,//寡妇
	};
	//请求发启者
	class IWomen
	{
	public:
		IWomen(){}
		virtual ~IWomen(){}
		virtual Type getType() = 0;
		virtual string getRequest() = 0;
	};

	class Women : public IWomen
	{
		Type m_type;
		string m_request;
	public:
		Women(Type type, string request) :m_type(type), m_request(request){}
		~Women()
		{
			cout << " ~Women()" << endl;
		}
		virtual Type getType() override
		{
			return m_type;
		}
		virtual string getRequest() override
		{
			switch ( m_type )
			{
			case Girl:
				return "女儿的请求是：" + m_request;
			case Wife:
				return "妻子的请求是：" + m_request;
			case Widow:
				return "母亲的请求是：" + m_request;
			default:
				break;
			}
			return "";
		}
	};

	//抽象处理者(Handler)
	class IHandler
	{
	protected:
		Type m_type;//处理级别
		//下一个责任人
		IHandler* m_pNext;

	public:
		IHandler( Type type):m_type(type){	}
		virtual ~IHandler(){}
		void handleMessage(IWomen* pWomen)
		{
			if (pWomen->getType() == m_type)
			{
				response(pWomen);
			}
			else
			{
				if (m_pNext)
				{
					m_pNext->handleMessage(pWomen);
				}
				else
				{
					cout << "没人处理了，不同意" << endl;
				}
			}
		}

		void setNext(IHandler* pHandler)
		{
			m_pNext = pHandler;
		}
		virtual void response(IWomen* pWomen) = 0;
	};

	class Father : public IHandler
	{
	public:
		Father(Type type = Girl) :IHandler(type){}
		virtual void response(IWomen* pWomen) override
		{
			cout << "--------女儿向父亲请求--------" << endl;
			cout << pWomen->getRequest() << endl;
			cout << "父亲的答复是：同意" << endl;
		}
	};

	class Husband : public IHandler
	{
	public:
		Husband(Type type = Wife) : IHandler(type){}
		virtual void response(IWomen* pWomen) override
		{
			cout << "--------妻子向丈夫请求--------" << endl;
			cout << pWomen->getRequest() << endl;
			cout << "丈夫的答复是：同意" << endl;
		}
	};

	class Son : public IHandler
	{
	public:
		Son(Type type = Widow) :IHandler(type){}
		virtual void response(IWomen* pWomen) override
		{
			cout << "--------母亲向儿子请求--------" << endl;
			cout << pWomen->getRequest() << endl;
			cout << "儿子的答复是：同意" << endl;
		}
	};
}

