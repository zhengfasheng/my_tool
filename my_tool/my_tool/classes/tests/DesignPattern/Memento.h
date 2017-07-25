#pragma once
#include <iostream>
#include <string>
using namespace std;
/*
//����¼ģʽ 

�ڲ��ƻ���װ�Ե�ǰ���£� ����һ��������ڲ�״
̬�� ���ڸö���֮�Ᵽ�����״̬�� �����Ժ�Ϳɽ��ö���ָ���ԭ�ȱ����״̬��

�� Originator�����˽�ɫ
��¼��ǰʱ�̵��ڲ�״̬�� ��������Щ���ڱ��ݷ�Χ��״̬�� ���𴴽��ͻָ�����¼
���ݡ�
�� Memento����¼��ɫ
����洢Originator�����˶�����ڲ�״̬�� ����Ҫ��ʱ���ṩ��������Ҫ���ڲ�״̬��
�� Caretaker����¼����Ա��ɫ
�Ա���¼���й��� ������ṩ����¼��

*/

namespace Memento
{
	//�������౸�ݷ����ߵ�״̬
	class Memento
	{
	public:
		//�����ʱ�򱸷�����
		Memento(string state) :_state(state){};
		string _state;
	};
	//�������౸���Լ���״̬
	class Originator
	{
	public:
		//��������
		Memento* createBackups(){
			return new Memento(_state);
		}
		//�ָ���������
		void restoreBackups(Memento* memento){
			_state = memento->_state;
		}
		//��ʾ״̬
		void show() {
			cout << _state << endl;
		}
		string _state;
	};
	//�������������
	class Caretaker
	{
	public:
		//�õ�����
		Memento* getMemento(){
			return _memento;
		}
		//���ñ���
		void setMemento(Memento* memento){
			_memento = memento;
		}
		Memento *_memento;
	};

}