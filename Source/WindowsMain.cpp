#include "Core.h"
#include "RenderWindow.h"
#include "RenderSystem.h"

int main(int argc, char *argv[])
{
	std::unique_ptr<CRenderSystem> render_system(new CRenderSystem());

	g_SystemCore->AddRenderWindow(640, 480, "Game window");
	g_SystemCore->InitialRenderWindows();
	g_SystemCore->UpdateRenderWindows();

	return 0;
}
