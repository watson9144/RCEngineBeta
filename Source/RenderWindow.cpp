#include "RenderWindow.h"
#include <assert.h>

CRenderWindow::CRenderWindow(unsigned int width, unsigned int height, const std::string& window_title)
{
	//初始化SDL2
	SDL_Init(SDL_INIT_VIDEO);
	//生成窗口属性
	m_RenderWindow = SDL_CreateWindow(window_title.data(),
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		width, height, SDL_WINDOW_OPENGL);

	assert(m_RenderWindow, "");
}

CRenderWindow::~CRenderWindow()
{
	SDL_DestroyWindow(m_RenderWindow);
}

void CRenderWindow::InitializeSystems()
{
	for (auto& sys : m_Systems)
	{
		if (sys->Initialize() != SYSTEM_ACTIVITY_SUCCEED)
		{
			printf("系统初始化出错\n");
		}
	}
}

void CRenderWindow::UpdateSystems()
{
	for (auto& sys : m_Systems)
	{
		if (sys->Update(1.0) != SYSTEM_ACTIVITY_SUCCEED)
		{
			printf("系统更新出错\n");
		}
	}
}

void CRenderWindow::TerminateSystems()
{
	for (auto& sys : m_Systems)
	{
		if (sys->Terminate() != SYSTEM_ACTIVITY_SUCCEED)
		{
			printf("系统终止出错\n");
		}
	}
}
