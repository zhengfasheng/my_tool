#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
状态模式
当一个对象内在状态改变时允许其改变行为， 这个对象看起来像改变了其
类。

● State——抽象状态角色
接口或抽象类， 负责对象状态定义， 并且封装环境角色以实现状态切换。
● ConcreteState——具体状态角色
每一个具体状态必须完成两个职责： 本状态的行为管理以及趋向状态处理， 通俗地说，
就是本状态下要做的事情， 以及本状态如何过渡到其他状态。
● Context——环境角色
定义客户端需要的接口， 并且负责具体状态的切换。

以电梯为例
			开门	关门	运行	停止
敞门状态	○	    ☆      ○      ○
闭门状态    ☆      ○      ☆      ☆
运行状态    ○      ○      ○      ☆
停止状态    ☆      ○      ☆      ○

电梯状态和动作对应表（ ○表示不允许， ☆表示允许动作）

*/
namespace State
{
	
	class Context;
	//State
	class IState
	{
	protected:
		Context* m_pContext;
	public:
		IState():m_pContext(nullptr){}
		virtual ~IState()
		{
			m_pContext = nullptr;
		}
		virtual void open(){}
		virtual void close(){}
		virtual void run(){}
		virtual void stop(){}
		virtual void setContext(Context* pContext)
		{
			m_pContext = pContext;
		}
	};

	//ConcreteState——具体状态角色
	//开门状态(只能关门)
	class OpenState : public IState
	{
	public:
		//本状态下必须处理的逻辑
		virtual void open() override;
		virtual void close() override;
	};

	//闭门状态
	class CloseState : public IState
	{
	public:
		virtual void open() override;
		//本状态下必须处理的逻辑
		virtual void close() override;
		virtual void run() override;
		virtual void stop() override;
	};

	//运行状态(只允许停止)
	class RunState : public IState
	{
	public:
		//本状态下必须处理的逻辑
		virtual void run() override;
		virtual void stop() override;
	};

	//停止状态(开门/运行)
	class StopState : public IState
	{
	public:
		virtual void open() override;
		virtual void run() override;
		//本状态下必须处理的逻辑
		virtual void stop() override;
	};

	//Context——环境角色
	class Context
	{
	public:
		static OpenState* s_pOpenState;
		static CloseState* s_pCloseState;
		static RunState* s_pRunState;
		static StopState* s_pStopState;
	private:
		IState* m_pCurState;//当前电梯状态

	public:
		Context() :m_pCurState(nullptr){}
		~Context()
		{
			m_pCurState = nullptr;
			release();
		}

		//设置当前电梯的运行状态
		void setState(IState* pState)
		{
			m_pCurState = pState;
			m_pCurState->setContext(this);
		}

		//得到当前电梯的运行状态
		IState* getState()
		{
			return m_pCurState;
		}

		//开门
		void open()
		{
			m_pCurState->open();
		}
		//关门
		void close()
		{
			m_pCurState->close();
		}
		//运行
		void run()
		{
			m_pCurState->run();
		}
		//停止
		void stop()
		{
			m_pCurState->stop();
		}

		//清理数据
		void release()
		{
			delete s_pCloseState;
			delete s_pOpenState;
			delete s_pRunState;
			delete s_pStopState;
			s_pCloseState = nullptr;
			s_pOpenState = nullptr;
			s_pRunState = nullptr;
			s_pStopState = nullptr;
		}
	};

}