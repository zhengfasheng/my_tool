#include "Visitor.h"

namespace visitor
{


	Element::~Element()
	{
		if (m_pVisitor)
			delete m_pVisitor;
		m_pVisitor = nullptr;
	}


	void ElementOne::accept(IVisitor* pVisitor)
	{
		m_pVisitor = pVisitor;
		if (pVisitor)
			pVisitor->visit(this);
	}


	void ElementTwo::accept(IVisitor* pVisitor)
	{
		m_pVisitor = pVisitor;
		if (pVisitor)
			pVisitor->visit(this);
	}


	void ElementThree::accept(IVisitor* pVisitor)
	{
		m_pVisitor = pVisitor;
		if (pVisitor)
			pVisitor->visit(this);
	}

}