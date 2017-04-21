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
