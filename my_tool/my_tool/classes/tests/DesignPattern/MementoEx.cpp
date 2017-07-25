
#include "MementoEx.h"

namespace MementoEx
{

	size_t Caretaker::m_id = 1;
	World::~World()
	{
		if (m_pCaretaker)
		{
			delete m_pCaretaker;
			m_pCaretaker = nullptr;
		}
	}

	void World::createMemento()
	{
		if (m_pCaretaker == nullptr)
			m_pCaretaker = new Caretaker;
		if (m_pCaretaker)
		{
			m_pCaretaker->addMemento(new Memento(m_content));
		}
	}

	bool World::restoreMemento(size_t id)
	{
		auto pMemento = m_pCaretaker->getMemento(id);
		if ( pMemento )
		{
			m_content = pMemento->getContent();
			return true;
		}
		cout << "no find this memento" << endl;
		return false;
	}

	void World::displayAllMemento()
	{
		if (m_pCaretaker)
		{
			m_pCaretaker->display();
		}
	}

}