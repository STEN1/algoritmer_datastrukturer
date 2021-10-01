
#include "sprite.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include "textures.h"



const float Sprite::vertices[] = {
	// positions          // colors           // texture coords
	 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
	 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
}; // c: 0 1 2, b: 8 9 10, a: 16 17 18, d: 24 25 26.

const unsigned int Sprite::indices[] = {
	0, 1, 3,  // first Triangle
	1, 2, 3   // second Triangle
};



Sprite::Sprite(Shader* shader, const std::string& texture_path, const Rect& rect)
	:shader(shader)
{
	
	texture = load_texture(texture_path.c_str());

	for (size_t i = 0; i < sizeof(vertices)/sizeof(float); i++)
	{
		sprite_vertices[i] = vertices[i];
	}

	sprite_vertices[16] = rect.a.x;
	sprite_vertices[17] = rect.a.y;
	sprite_vertices[8] = rect.b.x;
	sprite_vertices[9] = rect.b.y;
	sprite_vertices[0] = rect.c.x;
	sprite_vertices[1] = rect.c.y;
	sprite_vertices[24] = rect.d.x;
	sprite_vertices[25] = rect.d.y;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);
	// bind vertex buffer object
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_vertices), sprite_vertices, GL_STATIC_DRAW);
	// bind element buffer object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// UV
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

Sprite::~Sprite()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Sprite::Render()
{
	shader->use();
	glBindTexture(GL_TEXTURE_2D, texture);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Shader* Sprite::get_shader()
{
	return shader;
}

