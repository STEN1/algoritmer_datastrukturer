#include "gameobject.h"


GameObject::GameObject(const std::string& name, const Vector2d& pos, Shader* shader, const std::string& texture)
	:name(name),
	pos(pos),
	scale(0.1),
	sprite(shader, texture, rect.offset(pos)),
	rect({ {-0.1 * scale, -0.1 * scale}, {0.1 * scale, -0.1 * scale}, {0.1 * scale, 0.1 * scale}, {-0.1 * scale, 0.1 * scale} })
{
}

std::ostream& operator<<(std::ostream& out, const GameObject& r)
{
	out << r.name << ' ' << r.pos;
	return out;
}