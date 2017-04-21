#pragma once
#include <windows.h>
#include <memory>
#include <SDL.h>
#include <string>

struct SDL_Window;
//窗口管理类
class CRenderWindow
{	
public:
	CRenderWindow(unsigned int width, unsigned int height, const std::string& window_title);
	~CRenderWindow();

	inline unsigned int GetWidth() { return m_WindowWidth; }
	inline unsigned int GetHeight() { return m_WindowHeight; }
	SDL_Window* GetWindow() { return m_RenderWindow; }
private:
	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;

	SDL_Window* m_RenderWindow;
};
