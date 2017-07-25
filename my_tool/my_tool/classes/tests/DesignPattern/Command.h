#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
��һ�������װ��һ������ �Ӷ�����ʹ�ò�ͬ������ѿͻ��˲������� ����
���Ŷӻ��߼�¼������־�� �����ṩ����ĳ����ͻָ����ܡ�
�� Receive�����߽�ɫ
�ý�ɫ���Ǹɻ�Ľ�ɫ�� ����ݵ�������Ӧ�ñ�ִ�е�
�� Command�����ɫ
��Ҫִ�е��������������������
�� Invoker�����߽�ɫ
���յ���� ��ִ�����

���ӻ�������Ľ����ߣ�ң����������ķ����ߣ�
ң��������һЩ��ť����ͬ�İ�ť��Ӧ���ӻ��Ĳ�ͬ������
���������ɫ��һ������ӿ������ݣ�
�����������������ʵ���˳�������ӿڣ�
����������������ֱ�������ֲ������򿪵��ӻ����رյ��ӻ����л�Ƶ����
��Ȼ�����ӻ�ң��������һ�����͵�����ģʽӦ��ʵ����
*/

#include <list>
#include <map>
namespace Command{

	//Receive(������)
	class TV
	{
		bool m_bIsOpen;//�Ƿ��
		int m_nChannel;//��ǰƵ��
	public:
		TV() :m_bIsOpen(false), m_nChannel(0){}
		void open()
		{
			if (m_bIsOpen)
			{
				cout << "��ǰ���ǿ���״̬��������Ч" << endl;
				return;
			}
			m_bIsOpen = !m_bIsOpen;
			display();
		}

		void close()
		{
			if (!m_bIsOpen)
			{
				cout << "��ǰ���ǹػ�״̬��������Ч" << endl;
				return;
			}
			m_bIsOpen = !m_bIsOpen;
			display();
		}

		void changeChannel(int channel)
		{
			if (!m_bIsOpen)
			{
				cout << "��ǰ���ǹػ�״̬��������Ч" << endl;
				return;
			}
			if (m_nChannel == channel)
			{
				cout << "��ǰ������Ƶ��" << m_nChannel << ",������Ч" << endl;
				return;
			}
			m_nChannel = channel;
			display();
		}

		void display()
		{
			cout << "--------��ǰ״̬--------" << endl;
			cout << "����״̬��" << (m_bIsOpen ? "����" : "�ػ�") << endl;
			cout << "��ǰƵ����" << m_nChannel << endl;
			cout << "------------------------" << endl;
		}
	};

	//��������
	class ICommand
	{
	public:
		ICommand( ){}
		virtual ~ICommand();
		virtual void execute() = 0;
		virtual void display()
		{
			cout << getName() << endl;
		};//��ʾ��ǰ������Ϣ
		virtual string getName() const = 0;//��������
	};

	//����
	class OpenCommand : public ICommand
	{
		TV* m_receiveTV;
	public:
		OpenCommand(TV* tv) :m_receiveTV(tv){}
		virtual void execute() override
		{
			m_receiveTV->open();
		}

		virtual string getName() const override
		{
			return "open";
		}
	};

	//�ػ�
	class CloseCommand : public ICommand
	{
		TV* m_receiveTV;
	public:
		CloseCommand(TV* tv) :m_receiveTV(tv){  };
		virtual void execute() override
		{
			m_receiveTV->close();
		}
		virtual string getName() const override
		{
			return "close";
		}
	};

	//�л�Ƶ��
	class ChangeCommand :public ICommand
	{
		int m_Channel;
		TV* m_receiveTV;
	public:
		ChangeCommand(TV* tv, int channel) : m_receiveTV(tv),m_Channel(channel){}
		virtual void execute() override
		{
			m_receiveTV->changeChannel(m_Channel);
		}
		virtual void display() override
		{
			cout << getName() << " , channel is " << m_Channel << endl;
		}

		virtual string getName() const override
		{
			return "change channel";
		}
	};

	class Control;

	//������һ������
	class UndoCommand : public ICommand
	{
		Control* m_pControl;//ң����
	public:
		UndoCommand(Control* pControl) :m_pControl(pControl){}
		virtual void execute() override;
		virtual string getName() const override
		{
			return "undo";
		}
	};

	//�ָ���һ������
	class RecoverCommand : public ICommand
	{
		Control* m_pControl;//ң����
	public:
		RecoverCommand(Control* pContorl) :m_pControl(pContorl){}
		virtual void execute() override;
		virtual string getName() const override
		{
			return "recover";
		}
	};

	//Invoker������(ң����)
	class Control { 
		
		list<ICommand*> m_finishCommands;//�Ѿ�ִ�е�����
		list<ICommand*> m_recoverCommands;//�ȴ��ָ�������

	public:
		Control(){}
		~Control(){
			m_finishCommands.clear();
			m_recoverCommands.clear();
		}
		

		//���ý�Ҫִ�е�����
		void executeCommand(ICommand* pCommand)
		{
			if ( pCommand )
			{
				cout << "ִ�����";
				pCommand->display();
				pCommand->execute();
				cout << endl;
				if (dynamic_cast<UndoCommand*>(pCommand) || dynamic_cast<RecoverCommand*>(pCommand))
				{
					//�����������
					return;
				}
				m_finishCommands.push_back(pCommand);
			}
		}

		//����
		void undo()
		{
			if (m_finishCommands.size() > 0)
			{
				cout << "�������";
				ICommand* pCommand = m_finishCommands.back();
				pCommand->display();
				//���Ѿ����������ɾ��
				m_finishCommands.pop_back();
				//���ӵ��ָ�������
				m_recoverCommands.push_back(pCommand);
				if (m_finishCommands.size() > 0)
				{
					//�õ���һ������
					pCommand = m_finishCommands.back();
					//�ָ�
					cout << "�ָ����";
					pCommand->display();
					cout << endl;
					pCommand->execute();
				}

			}
		}

		//�ָ�
		void recover()
		{
			if (m_recoverCommands.size() > 0)
			{
				cout << "�ָ����";
				ICommand* pCommand = m_recoverCommands.back();
				pCommand->display();
				cout << endl;
				pCommand->execute();
				m_recoverCommands.pop_back();
				m_finishCommands.push_back(pCommand);
			}
		}


	};
}