#include "State.h"

namespace State
{
	OpenState* Context::s_pOpenState = new OpenState;
	CloseState* Context::s_pCloseState = new CloseState;
	RunState* Context::s_pRunState = new RunState;
	StopState* Context::s_pStopState = new StopState;

	void OpenState::close()
	{
		if (m_pContext)
		{
			m_pContext->setState(Context::s_pCloseState);
			m_pContext->getState()->close();
		}
	}

	void OpenState::open()
	{
		cout << "电梯开门..." << endl;
	}

	//电梯关门再开
	void CloseState::open()
	{
		if (m_pContext)
		{
			m_pContext->setState(Context::s_pOpenState);
			m_pContext->getState()->open();
		}
	}

	//要实现的关门逻辑
	void CloseState::close()
	{
		cout << "电梯关门..." << endl;
	}

	//电梯关门后运行
	void CloseState::run()
	{
		if ( m_pContext )
		{
			m_pContext->setState(Context::s_pRunState);
			m_pContext->getState()->run();
		}
	}

	//电梯关门后停止
	void CloseState::stop()
	{
		if ( m_pContext )
		{
			m_pContext->setState(Context::s_pStopState);
			m_pContext->getState()->stop();
		}
	}


	void RunState::run()
	{
		cout << "电梯正在上下运行..." << endl;
	}

	void RunState::stop()
	{
		if ( m_pContext )
		{
			m_pContext->setState(Context::s_pStopState);
			m_pContext->getState()->stop();
		}
	}


	void StopState::open()
	{
		if ( m_pContext )
		{
			m_pContext->setState(Context::s_pOpenState);
			m_pContext->getState()->open();
		}
	}

	void StopState::run()
	{
		if ( m_pContext )
		{
			m_pContext->setState(Context::s_pRunState);
			m_pContext->getState()->run();
		}
	}

	void StopState::stop()
	{
		cout << "电梯停止..." << endl;
	}

}