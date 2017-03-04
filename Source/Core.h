#pragma once
#include <memory>
#include <vector>
//系统核心
//class CSystemBase;
#include "SystemBase.h"

class CSystemCore
{
public:
	void AddSystem(std::unique_ptr<CSystemBase> a_system);

	void InitializeSystems();
	void UpdateSystems();
	void TerminateSystems();

private:
	std::vector<std::unique_ptr<CSystemBase>> m_Systems;
};

extern std::unique_ptr<CSystemCore> g_SystemCore;