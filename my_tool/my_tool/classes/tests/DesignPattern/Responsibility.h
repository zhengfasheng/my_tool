#pragma once
#include <iostream>
using namespace std;
/*
�ܶ������ÿһ����������¼ҵ����ö����������γ�һ������
������������ϴ��ݣ�ֱ�����ϵ�ĳһ������������������
�����������Ŀͻ��˲���֪�����ϵ���һ���������մ����������
��ʹ��ϵͳ�����ڲ�Ӱ��ͻ��˵�����¶�̬��������֯�ͷ�������

������ģʽ�漰���Ľ�ɫ������ʾ��

�񡡳�������(Handler)��ɫ��
�����һ����������Ľӿڡ������Ҫ��
�ӿڿ��Զ��� ��һ���������趨�ͷ��ض��¼ҵ����á�
�����ɫͨ����һ��Java���������Java�ӿ�ʵ�֡�
��ͼ��Handler��ľۺϹ�ϵ�����˾���������¼ҵ����ã�
���󷽷�handleRequest()�淶�����ദ������Ĳ�����

�񡡾��崦����(ConcreteHandler)��ɫ��
���崦���߽ӵ�����󣬿���ѡ�����������
���߽����󴫸��¼ҡ����ھ��崦���߳��ж��¼ҵ����ã�
��ˣ������Ҫ�����崦���߿��Է����¼ҡ�


�й��Ŵ��Ը�Ů�ƶ��ˡ������ĵ¡��ĵ��¹淶�� �����ӡ���ָ��δ�޴Ӹ��� �ȼ޴ӷ� ��
�����ӡ��� Ҳ����˵�� һλŮ���ڽ��֮ǰҪ�����ڸ��ף� ���֮��Ҫ�������ɷ� �����
�����˻�Ҫ�����ڶ��ӡ� ������˵�� ���һλŮ��Ҫ��ȥ��֣� ��������ǰ�������ø��׵�
ͬ�⣬ ����֮��������ɷ����ɣ� ���ɷ�������ô�죿 �Ǿ͵����ʶ����Ƿ������Լ���
ȥ��֡� ���������������Ҫ�ʣ� ��Ҫ��û�ж�����ô�죿 ���Ǿ���ʾС���ӡ� ֶ�ӵȡ� �ڸ�
ϵ����У� ��Ůֻռ������λ�� ���������й��Ŵ��ĸ�Ů����ͦ���ҵģ� ����ֶ�Ҫ�෬��
ʾ�� ��Ϊ���ס� �ɷ����ӣ� ֻ������ѡ�� Ҫ���е����������� ����������������֣�
Ҫ����������ʾ��һ���ˣ� �������������ϵ��Լ���� Ӧ�õ�������Ŀ�о���ҵ����� ��
���������ͨ��������ʵ�֡����ӡ���
*/

#include <iostream>
#include <string>
using namespace std;
namespace Responsibility
{
	enum Type
	{
		Girl,//δ����
		Wife,//����
		Widow,//�Ѹ�
	};
	//��������
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
				return "Ů���������ǣ�" + m_request;
			case Wife:
				return "���ӵ������ǣ�" + m_request;
			case Widow:
				return "ĸ�׵������ǣ�" + m_request;
			default:
				break;
			}
			return "";
		}
	};

	//��������(Handler)
	class IHandler
	{
	protected:
		Type m_type;//������
		//��һ��������
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
					cout << "û�˴����ˣ���ͬ��" << endl;
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
			cout << "--------Ů����������--------" << endl;
			cout << pWomen->getRequest() << endl;
			cout << "���׵Ĵ��ǣ�ͬ��" << endl;
		}
	};

	class Husband : public IHandler
	{
	public:
		Husband(Type type = Wife) : IHandler(type){}
		virtual void response(IWomen* pWomen) override
		{
			cout << "--------�������ɷ�����--------" << endl;
			cout << pWomen->getRequest() << endl;
			cout << "�ɷ�Ĵ��ǣ�ͬ��" << endl;
		}
	};

	class Son : public IHandler
	{
	public:
		Son(Type type = Widow) :IHandler(type){}
		virtual void response(IWomen* pWomen) override
		{
			cout << "--------ĸ�����������--------" << endl;
			cout << pWomen->getRequest() << endl;
			cout << "���ӵĴ��ǣ�ͬ��" << endl;
		}
	};
}

