#include "Core.h"

std::unique_ptr<CSystemCore> g_SystemCore(new CSystemCore);

void CSystemCore::AddSystem(std::unique_ptr<CSystemBase> a_system)
{
	m_Systems.push_back(std::move(a_system));
}

void CSystemCore::InitializeSystems()
{
	for (auto& sys : m_Systems)
	{
		if (sys->Initialize() != SYSTEM_ACTIVITY_SUCCEED)
		{
			printf("系统初始化出错\n");
		}
	}
}

void CSystemCore::UpdateSystems()
{
	//TODO: 时间
	for (auto& sys : m_Systems)
	{
		if (sys->Update(1.0) != SYSTEM_ACTIVITY_SUCCEED)
		{
			printf("系统更新出错\n");
		}
	}
}

void CSystemCore::TerminateSystems()
{
	for (auto& sys : m_Systems)
	{
		if (sys->Terminate() != SYSTEM_ACTIVITY_SUCCEED)
		{
			printf("系统终止出错\n");
		}
	}
}
