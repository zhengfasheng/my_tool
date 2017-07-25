#pragma once
#include "IDatabaseFactory.h"
#include "User.h"
#include "Department.h"

class SQLSeverDatabaseFactory :
	public IDatabaseFactory
{
public:
	SQLSeverDatabaseFactory(){}
	~SQLSeverDatabaseFactory(){}

	virtual IUser* createUser() override
	{
		return new SQLSeverUser;
	}

	virtual IDepartment* createDepartment() override
	{
		return new SQLSeverDepartment;
	}
};

class AccessDatabaseFactory :
	public IDatabaseFactory
{
public:
	AccessDatabaseFactory(){}
	~AccessDatabaseFactory(){}

	virtual IUser* createUser() override
	{
		return new AccessUser;
	}

	virtual IDepartment* createDepartment() override
	{
		return new AccessDepartment;
	}
};

class OracleDatabaseFactory :
	public IDatabaseFactory
{
public:
	OracleDatabaseFactory(){}
	~OracleDatabaseFactory(){}

	virtual IUser* createUser() override
	{
		return new OracleUser;
	}

	virtual IDepartment* createDepartment() override
	{
		return new OracleDepartment;
	}
};

