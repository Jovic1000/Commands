#pragma once
#include "CommandExecuter.h"
#include "IInstructionCommand.h"

void CommandExecuter::Request(IInstructionCommand* command)
{
	m_commandQueue.push(command);
}

void CommandExecuter::ExecuteRequest()
{
	if (m_commandQueue.front()->CanDoAction())
	{
		IInstructionCommand* command = m_commandQueue.front();
		command->DoAction();
		m_commandQueue.pop();
		delete command;

	}
}

CommandExecuter::CommandExecuter()
{
}
