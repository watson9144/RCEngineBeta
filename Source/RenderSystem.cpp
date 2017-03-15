#include "RenderSystem.h"
#include <SDL_opengl.h>

int CRenderSystem::Initialize()
{
	m_RenderWindow.reset(new CRenderWindow(640, 480, "RCEngine"));

	//设置用于清屏的颜色
	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, m_RenderWindow->GetWidth(), m_RenderWindow->GetHeight(), 0, -1, 1);

	//如果有错误的话
	if (glGetError() != GL_NO_ERROR)
	{
		return SYSTEM_ACTIVITY_FAILED;
	}


	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Update(double time_step)
{
	//开始绘制四边形
	glBegin(GL_QUADS);

	//将颜色设置为白色
	glColor4f(1.0, 1.0, 1.0, 1.0);
	//绘制四边形
	glVertex3f(0, 0, 0);
	glVertex3f(0.5, 0, 0);
	glVertex3f(0.5, 0.5, 0);
	glVertex3f(0, 0.5, 0);

	//结束绘制
	glEnd();

	glLoadIdentity();

	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Terminate()
{
	return SYSTEM_ACTIVITY_SUCCEED;
}