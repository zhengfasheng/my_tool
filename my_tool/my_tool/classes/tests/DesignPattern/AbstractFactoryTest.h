#pragma once
#include "ITest.h"
#include "DatabaseFactory.h"
class AbstractFactoryTest :
	public ITest
{
public:
	AbstractFactoryTest(){}
	~AbstractFactoryTest(){}
	virtual std::string getName() override
	{
		return "抽象工厂模式";
	}
	virtual void run() override
	{
		//SQLSever数据库
		cout << "--------SQLSever 数据库的操作--------" << endl;
		IDatabaseFactory* pFactory = new SQLSeverDatabaseFactory;

		IUser* pUser = pFactory->createUser();

		IDepartment* pDepartment = pFactory->createDepartment();

		pUser->insert();

		pUser->getUser();

		pDepartment->insert();

		pDepartment->getDepartment();


		SAVE_DELETE(pUser);
		SAVE_DELETE(pDepartment);
		SAVE_DELETE(pFactory);


		//Access数据库
		cout << "--------Access 数据库的操作--------" << endl;
		pFactory = new AccessDatabaseFactory;
		pUser = pFactory->createUser();
		pUser->insert();
		pUser->getUser();

		pDepartment = pFactory->createDepartment();
		pDepartment->insert();
		pDepartment->getDepartment();

		SAVE_DELETE(pUser);
		SAVE_DELETE(pDepartment);
		SAVE_DELETE(pFactory);

		//Oracle数据库
		cout << "--------Oracle 数据库的操作--------" << endl;
		pFactory = new OracleDatabaseFactory;
		pUser = pFactory->createUser();
		pUser->insert();
		pUser->getUser();

		pDepartment = pFactory->createDepartment();
		pDepartment->insert();
		pDepartment->getDepartment();

		SAVE_DELETE(pUser);
		SAVE_DELETE(pDepartment);
		SAVE_DELETE(pFactory);
	}
};

