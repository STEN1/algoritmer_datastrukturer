#pragma once
#include <iostream>
#include <string>
#include "vector2d.h"
#include "sprite.h"

class GameObject
{
public:
	Vector2d pos;
	std::string name;
	double scale;
	Rect rect;
	Sprite sprite;
	GameObject() = delete;
	GameObject(const GameObject&) = delete;
	GameObject(const std::string& name, const Vector2d& pos, Shader* shader, const std::string& texture);
};
std::ostream& operator << (std::ostream& out, const GameObject& r);