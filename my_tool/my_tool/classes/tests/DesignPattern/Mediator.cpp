
#include "Mediator.h"

Mediator::Person::~Person()
{
	//cout << m_name << "~Person()" << endl;
	m_mediator = nullptr;
	if (m_house)
		delete m_house;
	m_house = nullptr;
}

