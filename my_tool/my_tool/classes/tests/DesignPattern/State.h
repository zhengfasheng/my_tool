#pragma once
#include <iostream>
#include <string>
using namespace std;

/*
״̬ģʽ
��һ����������״̬�ı�ʱ������ı���Ϊ�� �������������ı�����
�ࡣ

�� State��������״̬��ɫ
�ӿڻ�����࣬ �������״̬���壬 ���ҷ�װ������ɫ��ʵ��״̬�л���
�� ConcreteState��������״̬��ɫ
ÿһ������״̬�����������ְ�� ��״̬����Ϊ�����Լ�����״̬���� ͨ�׵�˵��
���Ǳ�״̬��Ҫ�������飬 �Լ���״̬��ι��ɵ�����״̬��
�� Context����������ɫ
����ͻ�����Ҫ�Ľӿڣ� ���Ҹ������״̬���л���

�Ե���Ϊ��
			����	����	����	ֹͣ
����״̬	��	    ��      ��      ��
����״̬    ��      ��      ��      ��
����״̬    ��      ��      ��      ��
ֹͣ״̬    ��      ��      ��      ��

����״̬�Ͷ�����Ӧ�� ���ʾ������ ���ʾ��������

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

	//ConcreteState��������״̬��ɫ
	//����״̬(ֻ�ܹ���)
	class OpenState : public IState
	{
	public:
		//��״̬�±��봦����߼�
		virtual void open() override;
		virtual void close() override;
	};

	//����״̬
	class CloseState : public IState
	{
	public:
		virtual void open() override;
		//��״̬�±��봦����߼�
		virtual void close() override;
		virtual void run() override;
		virtual void stop() override;
	};

	//����״̬(ֻ����ֹͣ)
	class RunState : public IState
	{
	public:
		//��״̬�±��봦����߼�
		virtual void run() override;
		virtual void stop() override;
	};

	//ֹͣ״̬(����/����)
	class StopState : public IState
	{
	public:
		virtual void open() override;
		virtual void run() override;
		//��״̬�±��봦����߼�
		virtual void stop() override;
	};

	//Context����������ɫ
	class Context
	{
	public:
		static OpenState* s_pOpenState;
		static CloseState* s_pCloseState;
		static RunState* s_pRunState;
		static StopState* s_pStopState;
	private:
		IState* m_pCurState;//��ǰ����״̬

	public:
		Context() :m_pCurState(nullptr){}
		~Context()
		{
			m_pCurState = nullptr;
			release();
		}

		//���õ�ǰ���ݵ�����״̬
		void setState(IState* pState)
		{
			m_pCurState = pState;
			m_pCurState->setContext(this);
		}

		//�õ���ǰ���ݵ�����״̬
		IState* getState()
		{
			return m_pCurState;
		}

		//����
		void open()
		{
			m_pCurState->open();
		}
		//����
		void close()
		{
			m_pCurState->close();
		}
		//����
		void run()
		{
			m_pCurState->run();
		}
		//ֹͣ
		void stop()
		{
			m_pCurState->stop();
		}

		//��������
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