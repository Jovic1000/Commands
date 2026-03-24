#include "C_EfficientGather.h"
#include "IInstructionCommand.h"
#include <iostream>
#include <Windows.h>

void C_EfficientGather::GatherWood(Resources* resources)
{
	std::cout << "Gathering wood. Current Wood: " << resources->m_wood << std::endl;
	resources->m_wood += 70;
	resources->m_willPower -= 7;
	Sleep(4000);
	std::cout << "Wood: " << resources->m_wood << std::endl;
	std::cout << "Willpower: " << resources->m_willPower << std::endl;
}
