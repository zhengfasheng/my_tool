#pragma once
#include "ITest.h"
#include "Command.h"
class CommandTest : public ITest
{
public:
	virtual std::string getName() override
	{
		return "ÃüÁîÄ£Ê½";
	}
	virtual void run() override
	{
		using namespace Command;
		TV* pTv = new TV;
		Control* pControl = new Control;

		auto pOpen = new OpenCommand(pTv);
		pControl->executeCommand(pOpen);

		auto pChangeChannel10 = new ChangeCommand(pTv, 10);
		pControl->executeCommand(pChangeChannel10);

		auto pChangeChannel20 = new ChangeCommand(pTv, 20);
		pControl->executeCommand(pChangeChannel20);

		auto pChangeChannel30 = new ChangeCommand(pTv, 30);
		pControl->executeCommand(pChangeChannel30);

		auto pUndo = new UndoCommand(pControl);
		pControl->executeCommand(pUndo);
		pControl->executeCommand(pUndo);
		pControl->executeCommand(pUndo);

		auto pRecover = new RecoverCommand(pControl);
		pControl->executeCommand(pRecover);
		pControl->executeCommand(pRecover);
		pControl->executeCommand(pRecover);

		auto pClose = new CloseCommand(pTv);
		pControl->executeCommand(pClose);

		//pControl->executeCommand(pClose);

		delete pOpen;
		delete pClose;
		delete pChangeChannel10;
		delete pChangeChannel20;
		delete pChangeChannel30;
		delete pUndo;
		delete pRecover;
		delete pTv;
		delete pControl;

	}
};