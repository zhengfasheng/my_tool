#pragma once
#include "IDepartment.h"
//
class SQLSeverDepartment :
	public IDepartment
{
public:
	SQLSeverDepartment()
	{
	}
	~SQLSeverDepartment()
	{
	}
	virtual void insert() override
	{
		cout << "��SQLSever�в���һ��<����>����" << endl;
	}
	virtual void getDepartment() override
	{
		cout << "��SQLSever�еõ�һ��<����>����" << endl;
	}
};

class AccessDepartment :
	public IDepartment
{
public:
	AccessDepartment(){}
	~AccessDepartment(){}
	virtual void insert() override
	{
		cout << "��Access�в���һ��<����>����" << endl;
	}
	virtual void getDepartment() override
	{
		cout << "��Access�еõ�һ��<����>����" << endl;
	}
};

class OracleDepartment :
	public IDepartment
{
public:
	OracleDepartment(){}
	~OracleDepartment(){}
	virtual void insert() override
	{
		cout << "��Oracle�в���һ��<����>����" << endl;
	}
	virtual void getDepartment() override
	{
		cout << "��Oracle�еõ�һ��<����>����" << endl;
	}
};

