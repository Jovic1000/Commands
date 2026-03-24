#pragma once
#include <queue>


class Resources
{
public:

    int m_willPower;
	int m_wood;

private:

	
};

class BuildSystem
{
public:

	void BuildHut(Resources* resources);
	void Rest();

private:
};

class IGatherWood;
class Worker
{
public:

	void GatherWood(Resources* resources);


	Worker(IGatherWood* Strat);

private:

	IGatherWood* m_currentStrat;

};

class IInstructionCommand
{
public:

	virtual bool CanDoAction() = 0;
	virtual void DoAction() = 0;

private:

};

class BuildHutCommand : public IInstructionCommand
{
public:

	void DoAction() override;
	bool CanDoAction() override;

	BuildHutCommand(Resources* resorces, BuildSystem* build);
	~BuildHutCommand();

private:

	Resources* m_resorces;
	BuildSystem* m_build;

};

class GatherWoodCommand : public IInstructionCommand
{
public:

	void DoAction() override;
	bool CanDoAction() override;

	GatherWoodCommand(Resources* resorces, Worker* worker);
	~GatherWoodCommand();

private:

	Resources* m_resorces;
	Worker* m_worker;
};

