#pragma once
#include <windows.h>
#include <memory>
#include <SDL.h>
#include <string>
#include <vector>
#include "SystemBase.h"

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

	void AddSystem(std::unique_ptr<CSystemBase> a_system);

	void InitializeSystems();
	void UpdateWindow();

private:
	unsigned int m_WindowWidth;
	unsigned int m_WindowHeight;

	SDL_Window* m_RenderWindow;

	std::vector<std::unique_ptr<CSystemBase>> m_Systems;

	void UpdateSystems();
	void TerminateSystems();
	bool DoTerminate();
};