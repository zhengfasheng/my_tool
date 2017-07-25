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
		cout << "���ݿ���..." << endl;
	}

	//���ݹ����ٿ�
	void CloseState::open()
	{
		if (m_pContext)
		{
			m_pContext->setState(Context::s_pOpenState);
			m_pContext->getState()->open();
		}
	}

	//Ҫʵ�ֵĹ����߼�
	void CloseState::close()
	{
		cout << "���ݹ���..." << endl;
	}

	//���ݹ��ź�����
	void CloseState::run()
	{
		if ( m_pContext )
		{
			m_pContext->setState(Context::s_pRunState);
			m_pContext->getState()->run();
		}
	}

	//���ݹ��ź�ֹͣ
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
		cout << "����������������..." << endl;
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
		cout << "����ֹͣ..." << endl;
	}

}