#version 330 core

precision highp float;

in vec4 ex_Color;

void main(void)
{
	gl_FragColor = vec4(ex_Color);
}
