#include "Core.h"

std::unique_ptr<CSystemCore> g_SystemCore(new CSystemCore);

void CSystemCore::AddRenderWindow(unsigned int width, unsigned int height, const std::string& window_title)
{
	std::unique_ptr<CRenderWindow> render_window(new CRenderWindow(width, height, window_title));
}

void CSystemCore::InitialRenderWindows()
{
	//做些什么？
	for (int window_idx = 0; window_idx < m_RenderWindows.size(); ++window_idx)
	{
		m_RenderWindows[window_idx]->InitializeSystems();
	}
}

void CSystemCore::UpdateRenderWindows()
{
	while (m_RenderWindows.size() > 0)
	{
		for (int window_idx = 0; window_idx < m_RenderWindows.size(); ++window_idx)
		{
			m_RenderWindows[window_idx]->UpdateSystems();
		}
	}
}