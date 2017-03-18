#pragma once
#include <GL\glew.h>
#include <SDL_opengl.h>
#include <memory>
#include <string>
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
	//载入shader
	GLuint LoadShader(const std::string& shader_file_path, GLenum shader_type);
	GLint CheckShaderProgram(GLuint program_id);

private:
	//OPENGL初始化常量
	GLuint m_VertexBuffer;		//顶点buffer
	GLuint m_ColorBuffer;		//颜色buffer
	//TODO: buffers[2];确定顶点/颜色/法线等的位置	
	GLuint m_VertexArrayObject;
	
};