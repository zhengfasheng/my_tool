#pragma once
#include "IManager.h"
using namespace std;

class DesignPatternManager : public IManager
{
	IMPLEMENT_MANAGER(DesignPatternManager);

protected:
	using IManager::registerTest;
	virtual void registerTest() override;
	virtual bool isUsing() override { return false; }
};

