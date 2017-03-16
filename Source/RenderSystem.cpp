#include "RenderSystem.h"
#include <GL\glew.h>
#include <SDL_opengl.h>

int CRenderSystem::Initialize()
{
	m_RenderWindow.reset(new CRenderWindow(640, 480, "RCEngine"));
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GLContext gl_context = SDL_GL_CreateContext(m_RenderWindow->GetWindow());
	if (!gl_context)
		return SYSTEM_ACTIVITY_FAILED;
	
	glewExperimental = GL_TRUE;

	glewInit();

	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Update(double time_step)
{
	glClearColor(1.0, 0.0, 0.5, 1.0);

	// Clear back buffer
	glClear(GL_COLOR_BUFFER_BIT);

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


	// Swap back and front buffer
	SDL_GL_SwapWindow(m_RenderWindow->GetWindow());
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Terminate()
{
	return SYSTEM_ACTIVITY_SUCCEED;
}