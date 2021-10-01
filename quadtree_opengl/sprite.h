#pragma once

#include <string>
#include "rect.h"

class Shader;
class Sprite
{
public:
	Sprite() = delete;
	Sprite(Shader* shader, const std::string& texture_path, const Rect& rect);
	~Sprite();

	void Render();
	Shader* get_shader();

private:
	unsigned int VAO, VBO, EBO, texture;

	static const float vertices[];
	static const unsigned int indices[];
	float sprite_vertices[32];

	Shader* shader;

};

