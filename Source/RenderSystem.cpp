#include <vector>
#include "Misc.h"
#include "RenderSystem.h"

GLuint vertex_array_id;
GLuint vertex_buffer;

const uint32_t points = 4;
const uint32_t floatsPerPoint = 3;

const GLfloat square[points][floatsPerPoint] =
{
	{ -0.5,  0.5,  0.5 }, // Top left
	{ 0.5,  0.5,  0.5 }, // Top right
	{ 0.5, -0.5,  0.5 }, // Bottom right 
	{ -0.5, -0.5,  0.5 }, // Bottom left
};

int CRenderSystem::Initialize()
{
	m_RenderWindow.reset(new CRenderWindow(640, 480, "RCEngine"));
	
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GLContext gl_context = SDL_GL_CreateContext(m_RenderWindow->GetWindow());
	if (!gl_context)
		return SYSTEM_ACTIVITY_FAILED;

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
		return SYSTEM_ACTIVITY_FAILED;

	glGenVertexArrays(1, &vertex_array_id);
	glBindVertexArray(vertex_array_id);

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, 12, square, GL_STATIC_DRAW);
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Update(double time_step)
{
	glClearColor(1.0, 0.0, 0.5, 1.0);

	// Clear back buffer
	glClear(GL_COLOR_BUFFER_BIT);


	glDrawArrays(GL_TRIANGLES, 0, 12);

	// Swap back and front buffer
	SDL_GL_SwapWindow(m_RenderWindow->GetWindow());
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Terminate()
{
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::LoadShader(const std::string& shader_file_path, GLenum shader_type)
{
	std::string shader_string = CFile::ReadFile(shader_file_path);
	char const* shader_string_ptr = shader_string.data();
	GLint size = shader_string.length();
	
	int shader_id = glCreateShader(shader_type);

	glShaderSource(shader_id, 1, &shader_string_ptr, &size);
	glCompileShader(shader_id);

	//检测shader
	GLint result = GL_FALSE;
	int info_log_length = 0;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &info_log_length);
	std::vector<char> shader_error_msg(info_log_length);
	glGetShaderInfoLog(shader_id, info_log_length, 0, &shader_error_msg[0]);
	fprintf(stdout, "%s\n", &shader_error_msg[0]);

	return shader_id;
}