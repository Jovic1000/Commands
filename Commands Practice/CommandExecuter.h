#pragma once
#include <queue>

class IInstructionCommand;
class CommandExecuter
{
public:

	void Request(IInstructionCommand* command);
	void ExecuteRequest();

	CommandExecuter();

private:

	std::queue<IInstructionCommand*> m_commandQueue;

};