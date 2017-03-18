#version 330

in vec3 in_Position;
in vec4 in_Color;

out vec4 ex_Color;

void main(void)
{
	gl_Position = vec4(in_Position.x, in_Position.y, in_Position.z, 1.0);
	ex_Color = in_Color;
}