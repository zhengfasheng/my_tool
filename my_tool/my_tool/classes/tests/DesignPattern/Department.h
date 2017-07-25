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
		cout << "向SQLSever中插入一条<部门>数据" << endl;
	}
	virtual void getDepartment() override
	{
		cout << "从SQLSever中得到一条<部门>数据" << endl;
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
		cout << "向Access中插入一条<部门>数据" << endl;
	}
	virtual void getDepartment() override
	{
		cout << "从Access中得到一条<部门>数据" << endl;
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
		cout << "向Oracle中插入一条<部门>数据" << endl;
	}
	virtual void getDepartment() override
	{
		cout << "从Oracle中得到一条<部门>数据" << endl;
	}
};

