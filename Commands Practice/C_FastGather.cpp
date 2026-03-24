#include "C_FastGather.h"
#include "IInstructionCommand.h"
#include <iostream>
#include <Windows.h>

void C_FastGather::GatherWood(Resources* resources)
{
	std::cout << "Gathering wood. Current Wood: " << resources->m_wood << std::endl;
	resources->m_wood += 20;
	resources->m_willPower -= 3;
	Sleep(1000);
	std::cout << "Wood: " << resources->m_wood << std::endl;
	std::cout << "Willpower: " << resources->m_willPower << std::endl;
}
