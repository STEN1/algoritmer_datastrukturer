#pragma once
#include <iostream>
#include "vector2d.h"

struct Rect
{
	Vector2d a, b, c, d;
	Vector2d mid();
	bool intersect(const Vector2d& pos);
	Rect& offset(const Vector2d& offset);
};
std::ostream& operator << (std::ostream& out, const Rect& r);