#include "IInstructionCommand.h"
#include "CommandExecuter.h"
#include "C_BaseGather.h"
#include "C_EfficientGather.h"
#include "C_FastGather.h"

int main()
{
	Resources resorces;
	BuildSystem build;

	C_BaseGather baseGather;
	C_EfficientGather efficientGather;
	C_FastGather fastGather;

	Worker workers(&fastGather);
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