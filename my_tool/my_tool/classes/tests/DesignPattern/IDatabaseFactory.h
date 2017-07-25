#pragma once
class IUser;
class IDepartment;
class IDatabaseFactory
{
public:
	IDatabaseFactory(){}
	virtual ~IDatabaseFactory(){}
	virtual IUser* createUser() = 0;
	virtual IDepartment* createDepartment() = 0;
};

