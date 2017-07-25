#pragma once
#include "ITest.h"
#include "Memento.h"
#include "MementoEx.h"

class MementoTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "����¼ģʽ";
	}

	virtual void run() override
	{
		//using namespace Memento;

		//auto pOriginator = new Originator;
		//pOriginator->_state = "ON";
		//pOriginator->show();

		//auto pMemento = pOriginator->createBackups();

		//auto pCaretaker = new Caretaker;
		//pCaretaker->setMemento(pMemento);

		//pOriginator->_state = "OFF";
		//pOriginator->show();

		////�ָ�
		//pOriginator->restoreBackups(pMemento);
		//pOriginator->show();

		//delete pOriginator;
		//delete pMemento;
		//delete pCaretaker;

		using namespace MementoEx;

		auto pWorld = new World;

		pWorld->setContent("zheng fa sheng ");

		pWorld->display();

		pWorld->createMemento();

		pWorld->setContent("this is a ... actually I don't known write for ");

		pWorld->display();

		pWorld->createMemento();

		pWorld->setContent("yes , but I don't known what to say ");

		pWorld->createMemento();

		pWorld->display();

		pWorld->displayAllMemento();

		size_t id;
		cout << "��ѡ��Ҫ�ָ���ID(0�˳�):" << endl;
		while (true)
		{
			cin >> id;
			if ( id == 0 )
			{
				break;
			}
			if (pWorld->restoreMemento(id))
			{
				pWorld->display();
			}
			
		}

		cin.get();

		delete pWorld;


	}
};