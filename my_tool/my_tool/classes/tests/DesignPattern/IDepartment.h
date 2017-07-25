#pragma once
#include <iostream>
using namespace std;
class IDepartment
{
public:
	IDepartment(){}
	virtual ~IDepartment(){}
	virtual void insert() = 0;
	virtual void getDepartment() = 0;
};

