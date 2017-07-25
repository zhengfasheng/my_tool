#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
将一个请求封装成一个对象， 从而让你使用不同的请求把客户端参数化， 对请
求排队或者记录请求日志， 可以提供命令的撤销和恢复功能。
● Receive接收者角色
该角色就是干活的角色， 命令传递到这里是应该被执行的
● Command命令角色
需要执行的所有命令都在这里声明。
● Invoker调用者角色
接收到命令， 并执行命令。

电视机是请求的接收者，遥控器是请求的发送者，
遥控器上有一些按钮，不同的按钮对应电视机的不同操作。
抽象命令角色由一个命令接口来扮演，
有三个具体的命令类实现了抽象命令接口，
这三个具体命令类分别代表三种操作：打开电视机、关闭电视机和切换频道。
显然，电视机遥控器就是一个典型的命令模式应用实例。
*/

#include <list>
#include <map>
namespace Command{

	//Receive(接收者)
	class TV
	{
		bool m_bIsOpen;//是否打开
		int m_nChannel;//当前频道
	public:
		TV() :m_bIsOpen(false), m_nChannel(0){}
		void open()
		{
			if (m_bIsOpen)
			{
				cout << "当前已是开机状态，命令无效" << endl;
				return;
			}
			m_bIsOpen = !m_bIsOpen;
			display();
		}

		void close()
		{
			if (!m_bIsOpen)
			{
				cout << "当前已是关机状态，命令无效" << endl;
				return;
			}
			m_bIsOpen = !m_bIsOpen;
			display();
		}

		void changeChannel(int channel)
		{
			if (!m_bIsOpen)
			{
				cout << "当前已是关机状态，命令无效" << endl;
				return;
			}
			if (m_nChannel == channel)
			{
				cout << "当前正处于频道" << m_nChannel << ",命令无效" << endl;
				return;
			}
			m_nChannel = channel;
			display();
		}

		void display()
		{
			cout << "--------当前状态--------" << endl;
			cout << "开机状态：" << (m_bIsOpen ? "开机" : "关机") << endl;
			cout << "当前频道：" << m_nChannel << endl;
			cout << "------------------------" << endl;
		}
	};

	//抽象命令
	class ICommand
	{
	public:
		ICommand( ){}
		virtual ~ICommand();
		virtual void execute() = 0;
		virtual void display()
		{
			cout << getName() << endl;
		};//显示当前命令信息
		virtual string getName() const = 0;//命令名称
	};

	//开机
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

	//关机
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

	//切换频道
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

	//撤消上一步操作
	class UndoCommand : public ICommand
	{
		Control* m_pControl;//遥控器
	public:
		UndoCommand(Control* pControl) :m_pControl(pControl){}
		virtual void execute() override;
		virtual string getName() const override
		{
			return "undo";
		}
	};

	//恢复上一步操作
	class RecoverCommand : public ICommand
	{
		Control* m_pControl;//遥控器
	public:
		RecoverCommand(Control* pContorl) :m_pControl(pContorl){}
		virtual void execute() override;
		virtual string getName() const override
		{
			return "recover";
		}
	};

	//Invoker调用者(遥控器)
	class Control { 
		
		list<ICommand*> m_finishCommands;//已经执行的命令
		list<ICommand*> m_recoverCommands;//等待恢复的命令

	public:
		Control(){}
		~Control(){
			m_finishCommands.clear();
			m_recoverCommands.clear();
		}
		

		//设置将要执行的命令
		void executeCommand(ICommand* pCommand)
		{
			if ( pCommand )
			{
				cout << "执行命令：";
				pCommand->display();
				pCommand->execute();
				cout << endl;
				if (dynamic_cast<UndoCommand*>(pCommand) || dynamic_cast<RecoverCommand*>(pCommand))
				{
					//这两个命令不放
					return;
				}
				m_finishCommands.push_back(pCommand);
			}
		}

		//撤消
		void undo()
		{
			if (m_finishCommands.size() > 0)
			{
				cout << "撤消命令：";
				ICommand* pCommand = m_finishCommands.back();
				pCommand->display();
				//从已经完成命令中删除
				m_finishCommands.pop_back();
				//增加到恢复队列中
				m_recoverCommands.push_back(pCommand);
				if (m_finishCommands.size() > 0)
				{
					//得到上一个命令
					pCommand = m_finishCommands.back();
					//恢复
					cout << "恢复命令：";
					pCommand->display();
					cout << endl;
					pCommand->execute();
				}

			}
		}

		//恢复
		void recover()
		{
			if (m_recoverCommands.size() > 0)
			{
				cout << "恢复命令：";
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