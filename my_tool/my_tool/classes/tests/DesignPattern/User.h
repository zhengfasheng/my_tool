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
		cout << "��SQLSever�в���һ��<�û�>����" << endl;
	}
	virtual void getUser() override
	{
		cout << "��SQLSever�еõ�һ��<�û�>����" << endl;
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
		cout << "��Access�в���һ��<�û�>����" << endl;
	}
	virtual void getUser() override
	{
		cout << "��Access�еõ�һ��<�û�>����" << endl;
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
		cout << "��Oracle�в���һ��<�û�>����" << endl;
	}
	virtual void getUser() override
	{
		cout << "��Oracle�еõ�һ��<�û�>����" << endl;
	}
};
