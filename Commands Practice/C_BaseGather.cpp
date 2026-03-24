#include "C_BaseGather.h"
#include <iostream>
#include <Windows.h>
#include "IInstructionCommand.h"

void C_BaseGather::GatherWood(Resources* resources)
{
	std::cout << "Gathering wood. Current Wood: " << resources->m_wood << std::endl;
	resources->m_wood += 50;
	resources->m_willPower -= 5;
	Sleep(2000);
	std::cout << "Wood: " << resources->m_wood << std::endl;
	std::cout << "Willpower: " << resources->m_willPower << std::endl;
}
