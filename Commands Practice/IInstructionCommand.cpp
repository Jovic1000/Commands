#include "IInstructionCommand.h"
#include "IGatherWood.h"
#include <iostream>
#include <Windows.h>

void Worker::GatherWood(Resources* resorces)
{
	m_currentStrat->GatherWood(resorces);
}

Worker::Worker(IGatherWood* strat) : m_currentStrat(strat)
{
}


void BuildSystem::BuildHut(Resources* resorces)
{
	std::cout << "Building... " << std::endl;
	resorces->m_wood -= 50;

	Rest();

	std::cout << "Built hut" << std::endl;

}

void BuildSystem::Rest()
{
	Sleep(3000);
}

void BuildHutCommand::DoAction()
{
	m_build->BuildHut(m_resorces);
}

bool BuildHutCommand::CanDoAction()
{
	return m_resorces->m_wood >= 50;
}

BuildHutCommand::BuildHutCommand(Resources* resorces, BuildSystem* build) : m_resorces(resorces), m_build(build)
{
}

BuildHutCommand::~BuildHutCommand()
{
}

void GatherWoodCommand::DoAction()
{
	m_worker->GatherWood(m_resorces);
}

bool GatherWoodCommand::CanDoAction()
{
	return m_resorces->m_willPower >= 5;
}

GatherWoodCommand::GatherWoodCommand(Resources* resorces, Worker* worker) : m_resorces(resorces), m_worker(worker)
{
}

GatherWoodCommand::~GatherWoodCommand()
{
}