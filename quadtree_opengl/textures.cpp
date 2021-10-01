#include "textures.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "libs/includes/stb_image/stb_image.h"

#include <iostream>
#include <unordered_map>
#include <string>
static std::unordered_map<std::string, unsigned int> texture_map;

unsigned int load_texture(const std::string& texture_path)
{
	auto iter = texture_map.find(texture_path);
	if (iter != texture_map.end())
	{
		std::cout << "Found in texture map: " << texture_path << std::endl;
		return iter->second;
	}
	else
	{
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// load and generate the texture
		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(texture_path.c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			std::cout << "Added to texture map: " << texture_path << std::endl;
		}
		else
		{
			std::cout << "Failed to load texture: " << texture_path << std::endl;
		}
		stbi_image_free(data);

		texture_map.emplace(texture_path, texture);

		return texture;
	}


}