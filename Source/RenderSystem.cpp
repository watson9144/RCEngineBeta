#include <vector>
#include <glm.hpp>
#include "Misc.h"
#include "RenderSystem.h"

const uint32_t points = 12;
const uint32_t floatsPerPoint = 3;
const uint32_t floatsPerColor = 4;

const GLfloat diamond[points][floatsPerPoint] = {
	{ 0.2,  0.2,  0.5 }, // Top right
	{ -0.2,  0.2,  0.5 }, // Top left
	{ 0.0,  0.0,  0.5 }, // Center

	{ 0.2,  0.2,  0.5 }, // Top right
	{ 0.2, -0.2,  0.5 }, // Bottom right 
	{ 0.0,  0.0,  0.5 }, // Center

	{ -0.2, -0.2,  0.5 }, // Bottom left
	{ 0.2, -0.2,  0.5 }, // Bottom right 
	{ 0.0,  0.0,  0.5 }, // Center

	{ -0.2, -0.2,  0.5 }, // Bottom left
	{ -0.2,  0.2,  0.5 }, // Top left
	{ 0.0,  0.0,  0.5 }, // Center
};

const GLfloat colors[points][floatsPerColor] = {
	{ 0.5, 0.5, 0.5, 1.0f }, // Top right
	{ 0.5, 0.5, 0.5, 1.0f }, // Bottom right 
	{ 0.0, 0.0, 0.0, 1.0f }, // Center

	{ 0.5, 0.5, 0.5, 1.0f }, // Top left
	{ 0.5, 0.5, 0.5, 1.0f }, // Top right
	{ 0.0, 0.0, 0.0, 1.0f }, // Center

	{ 0.5, 0.5, 0.5, 1.0f }, // Bottom left
	{ 0.5, 0.5, 0.5, 1.0f }, // Bottom right 
	{ 0.0, 0.0, 0.0, 1.0f }, // Center

	{ 0.5, 0.5, 0.5, 1.0f }, // Bottom left
	{ 0.5, 0.5, 0.5, 1.0f }, // Top left
	{ 0.0, 0.0, 0.0, 1.0f }, // Center
};

GLuint vbo[2], vao[1];
const uint32_t positionAttributeIndex = 1, colorAttributeIndex = 0;

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

	glGenBuffers(1, &m_VertexBuffer);
	glGenBuffers(1, &m_ColorBuffer);
	glGenVertexArrays(1, &m_VertexArrayObject);
	glBindVertexArray(m_VertexArrayObject);


	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, (points*floatsPerPoint) * sizeof(GLfloat), diamond, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, m_ColorBuffer);
	glBufferData(GL_ARRAY_BUFFER, (points*floatsPerColor) * sizeof(GLfloat), colors, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	GLuint shader_program = glCreateProgram();

	GLuint vs_id = LoadShader("Shaders/vert.glsl", GL_VERTEX_SHADER);
	glAttachShader(shader_program, vs_id);
	GLuint fs_id = LoadShader("Shaders/frag.glsl", GL_FRAGMENT_SHADER);
	glAttachShader(shader_program, fs_id);

	glLinkProgram(shader_program);
	GLuint result = CheckShaderProgram(shader_program);
	if (result != GL_TRUE)
		return SYSTEM_ACTIVITY_FAILED;

	glUseProgram(shader_program);

	glDeleteShader(vs_id);
	glDeleteShader(fs_id);


	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Update(double time_step)
{
	glClearColor(1.0, 0.0, 0.5, 1.0);
	// Clear back buffer
	glClear(GL_COLOR_BUFFER_BIT);


	glDrawArrays(GL_TRIANGLES, 0, points);

	// Swap back and front buffer
	SDL_GL_SwapWindow(m_RenderWindow->GetWindow());
	return SYSTEM_ACTIVITY_SUCCEED;
}

int CRenderSystem::Terminate()
{
	return SYSTEM_ACTIVITY_SUCCEED;
}

GLuint CRenderSystem::LoadShader(const std::string& shader_file_path, GLenum shader_type)
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
	if (info_log_length > 0)
	{
		std::vector<char> shader_error_msg(info_log_length);
		glGetShaderInfoLog(shader_id, info_log_length, 0, &shader_error_msg[0]);
		fprintf(stdout, "%s\n", &shader_error_msg[0]);
	}
	return shader_id;
}

GLint CRenderSystem::CheckShaderProgram(GLuint program_id)
{
	GLint result = GL_FALSE;
	int info_log_length = 0;

	glGetProgramiv(program_id, GL_LINK_STATUS, &result);
	glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &info_log_length);
	std::vector<char> program_error_msg(max(info_log_length, int(1)));
	glGetProgramInfoLog(program_id, info_log_length, nullptr, &program_error_msg[0]);
	fprintf(stdout, "%s\n", &program_error_msg[0]);

	return result;
}