
#include "Command.h"

void Command::UndoCommand::execute()
{
	m_pControl->undo();
}

void Command::RecoverCommand::execute()
{
	m_pControl->recover();
}

Command::ICommand::~ICommand()
{
	//cout << getName() << endl;
	//cout << "ICommand" << endl;
}
