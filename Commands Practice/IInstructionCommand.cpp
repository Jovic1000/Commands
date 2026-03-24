#include "IInstructionCommand.h"
#include <iostream>
#include <Windows.h>

void Worker::GatherWood(Resorces* resorces)
{
	std::cout << "Gathering wood. Current Wood: " << resorces->m_wood << std::endl;
	resorces->m_wood += 50;
	resorces->m_willPower -= 5;
	Sleep(2000);
	std::cout << "Wood: " << resorces->m_wood << std::endl;
	std::cout << "Willpower: " << resorces->m_willPower << std::endl;
}

void BuildSystem::BuildHut(Resorces* resorces)
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

BuildHutCommand::BuildHutCommand(Resorces* resorces, BuildSystem* build) : m_resorces(resorces), m_build(build)
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

GatherWoodCommand::GatherWoodCommand(Resorces* resorces, Worker* worker) : m_resorces(resorces), m_worker(worker)
{
}

GatherWoodCommand::~GatherWoodCommand()
{
}