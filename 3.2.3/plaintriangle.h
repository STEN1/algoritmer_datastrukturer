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
	Vector2d operator-(const Vector2d& rhs) const
	{
		return { x - rhs.x, y - rhs.y };
	}
	double size()
	{
		return sqrt(x * x + y * y);
	}
};

class PlainTriangle
{
public:
	PlainTriangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3);

	static void subDivide(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, double minArea);
	static void print();

private:
	static double calcArea(const PlainTriangle& tri);
	Vector2d m_v1;
	Vector2d m_v2;
	Vector2d m_v3;

	static std::vector<PlainTriangle> s_triangles;
};