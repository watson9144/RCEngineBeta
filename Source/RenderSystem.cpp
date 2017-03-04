#include "RenderSystem.h"

int CRenderSystem::Initialize()
{
	m_RenderWindow.reset(new CRenderWindow(640, 480, "RCEngine"));
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Update(double time_step)
{
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Terminate()
{
	return SYSTEM_ACTIVITY_SUCCEED;
}