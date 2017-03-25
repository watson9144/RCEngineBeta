#pragma once
#include <memory>
#include <vector>
#include <string>
//系统核心
#include "RenderWindow.h"

class CSystemCore
{
public:
	void AddRenderWindow(unsigned int width, unsigned int height, const std::string& window_title);
	void InitialRenderWindows();
	void UpdateRenderWindows();
	void TerminateRenderWindows();

private:
	std::vector<std::unique_ptr<CRenderWindow>> m_RenderWindows;
};

extern std::unique_ptr<CSystemCore> g_SystemCore;