#pragma once
#include <vector>

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
};

class PlainRectangle
{
public:
	PlainRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4);

	static void subDivide(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4, uint32_t n);
	static void print();

private:
	static double calcArea(const PlainRectangle& rect);
	Vector2d m_v1;
	Vector2d m_v2;
	Vector2d m_v3;
	Vector2d m_v4;

	static std::vector<PlainRectangle> s_rectangles;
};