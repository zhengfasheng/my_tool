
#include "Composite.h"

namespace Composite
{


	void Pool::addChild(Ref* pChild)
	{
		m_children.push_back(pChild);
	}

	std::string Pool::getName() const
	{
		return "pool";
	}

	Pool* Pool::getInstance()
	{
		static Pool* p = nullptr;
		if (p == nullptr)
		{
			p = new Pool;
		}
		return p;
	}

	void Pool::tick()
	{
		for ( auto p : m_children )
		{
			p->release();
		}
	}


	void Ref::autorelease()
	{
		Pool::getInstance()->addChild(this);
	}

	void Ref::release()
	{
		--m_useCount;
		if (m_useCount == 0)
		{
			delete this;
		}
	}

	void Ref::retain()
	{
		++m_useCount;
	}

}