#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
��һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�
Adapterģʽʹ��ԭ�����ڽӿڲ�����
������һ��������Щ�����һ����

�� TargetĿ���ɫ
�ý�ɫ�����������ת��Ϊ���ֽӿڣ� Ҳ�������ǵ������ӿڣ� �����е�IUserInfo�ӿ�
����Ŀ���ɫ��
�� AdapteeԴ��ɫ
�����˭ת����Ŀ���ɫ�� �����˭������Դ��ɫ�� �����Ѿ����ڵġ� �������õ�����
�� ������������ɫ�İ�װ�� �����Ϊһ��ո�¡� �����Ľ�ɫ��
�� Adapter��������ɫ
������ģʽ�ĺ��Ľ�ɫ�� ����������ɫ�����Ѿ����ڵĽ�ɫ�� ����������ɫ����Ҫ�½�
���ģ� ����ְ��ǳ��򵥣� ��Դ��ɫת��ΪĿ���ɫ�� ��ôת���� ͨ���̳л���������ķ�
ʽ��
*/
namespace Adt {

	//TargetĿ���ɫ
	class Target
	{
	public: 
		Target(){}
		virtual ~Target(){}
		virtual void request() = 0;
	};

	//ConcreteTargetĿ���ɫʵ��
	class ConcreteTarget : public Target
	{
	public:
		virtual void request() override
		{
			cout << "I'm a concrete target" << endl;
		}
	};

	//AdapteeԴ��ɫ(��������)
	class Adaptee
	{
	public:
		Adaptee(){}
		virtual ~Adaptee(){}
		void doSomething()
		{
			cout << "I'm an adaptee" << endl;
		}
	};

	//��������ɫAdapter
	class Adapter : public Adaptee, public Target
	{
	public:
		virtual void request() override
		{
			doSomething();
		}
	};
}