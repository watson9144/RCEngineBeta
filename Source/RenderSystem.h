#pragma once
#include <memory>
#include "SystemBase.h"
//渲染系统,包含窗口创建管理等等
#include "RenderWindow.h"

class CRenderSystem : public CSystemBase
{
public:
	int Initialize() override;

	int Update(double time_step) override;

	int Terminate() override;

private:
	//先只支持一个窗口
	std::unique_ptr<CRenderWindow> m_RenderWindow;
};