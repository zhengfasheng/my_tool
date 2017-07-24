#pragma once
#include "common.h"

class ITest;
class AppDelegate
{
public:
	virtual ~AppDelegate();
	AppDelegate();

	virtual bool init();

	virtual void run();
private:
	vector<ITest*> m_tests;;
};