#pragma once
#include <iostream>

struct Vector2d
{
	double x;
	double y;

	Vector2d operator+(const Vector2d& rhs) const
	{
		return { x + rhs.x, y + rhs.y };
	}
	Vector2d operator/(const double& d) const
	{
		return { x / d, y / d };
	}
	Vector2d operator-(const Vector2d& rhs) const
	{
		return { x - rhs.x, y - rhs.y };
	}
	double size()
	{
		return sqrt(x * x + y * y);
	}
};
std::ostream& operator << (std::ostream& out, const Vector2d& v);