#include "IInstructionCommand.h"
#include "CommandExecuter.h"

int main()
{
	Resorces resorces;
	Worker workers;
	BuildSystem build;

	GatherWoodCommand* wood = new GatherWoodCommand(&resorces, &workers);
	BuildHutCommand* hut = new BuildHutCommand(&resorces, &build);
	CommandExecuter executer;

	//test 1
	{
		resorces.m_willPower = 50;
		resorces.m_wood = 50;

		workers.GatherWood(&resorces);

		build.BuildHut(&resorces);
	}

	//test 2
	{
		executer.Request(wood);
		executer.Request(hut);



		executer.ExecuteRequest();
		executer.ExecuteRequest();
	}

	return 0;
}