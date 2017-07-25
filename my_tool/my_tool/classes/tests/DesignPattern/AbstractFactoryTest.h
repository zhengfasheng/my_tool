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
		return "���󹤳�ģʽ";
	}
	virtual void run() override
	{
		//SQLSever���ݿ�
		cout << "--------SQLSever ���ݿ�Ĳ���--------" << endl;
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


		//Access���ݿ�
		cout << "--------Access ���ݿ�Ĳ���--------" << endl;
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

		//Oracle���ݿ�
		cout << "--------Oracle ���ݿ�Ĳ���--------" << endl;
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

