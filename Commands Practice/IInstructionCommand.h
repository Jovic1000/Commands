#pragma once
#include <queue>

class Resorces
{
public:

    int m_willPower;
	int m_wood;

private:

	
};

class BuildSystem
{
public:

	void BuildHut(Resorces* resorces);
	void Rest();

private:
};

class Worker
{
public:

	void GatherWood(Resorces* resorces);

private:

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

	BuildHutCommand(Resorces* resorces, BuildSystem* build);
	~BuildHutCommand();

private:

	Resorces* m_resorces;
	BuildSystem* m_build;

};

class GatherWoodCommand : public IInstructionCommand
{
public:

	void DoAction() override;
	bool CanDoAction() override;

	GatherWoodCommand(Resorces* resorces, Worker* worker);
	~GatherWoodCommand();

private:

	Resorces* m_resorces;
	Worker* m_worker;
};

