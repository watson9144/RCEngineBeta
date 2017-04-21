#include "Core.h"
#include "RenderWindow.h"
#include "RenderSystem.h"

int main(int argc, char *argv[])
{
	std::unique_ptr<CRenderSystem> render_system(new CRenderSystem());
	g_SystemCore->AddSystem(std::move(render_system));

	g_SystemCore->InitializeSystems();

	while (g_EngineRunning)
	{
		g_SystemCore->UpdateSystems();
	}

	g_SystemCore->TerminateSystems();

	return 0;
}
