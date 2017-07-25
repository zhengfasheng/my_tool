#pragma once
#include "IUser.h"
//
class SQLSeverUser :
	public IUser
{
public:
	SQLSeverUser()
	{
	}
	~SQLSeverUser()
	{
	}
	virtual void insert() override
	{
		cout << "向SQLSever中插入一条<用户>数据" << endl;
	}
	virtual void getUser() override
	{
		cout << "从SQLSever中得到一条<用户>数据" << endl;
	}
};

class AccessUser :
	public IUser
{
public:
	AccessUser(){}
	~AccessUser(){}
	virtual void insert() override
	{
		cout << "向Access中插入一条<用户>数据" << endl;
	}
	virtual void getUser() override
	{
		cout << "从Access中得到一条<用户>数据" << endl;
	}
};

class OracleUser :
	public IUser
{
public:
	OracleUser(){}
	~OracleUser(){}
	virtual void insert() override
	{
		cout << "向Oracle中插入一条<用户>数据" << endl;
	}
	virtual void getUser() override
	{
		cout << "从Oracle中得到一条<用户>数据" << endl;
	}
};
