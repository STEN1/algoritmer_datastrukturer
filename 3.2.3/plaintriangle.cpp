#include "plaintriangle.h"

#include <iostream>

std::vector<PlainTriangle> PlainTriangle::s_triangles;

PlainTriangle::PlainTriangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3)
	:m_v1(v1)
	,m_v2(v2)
	,m_v3(v3)
{
}

void PlainTriangle::subDivide(const Vector2d& a, const Vector2d& b, const Vector2d& c, double minArea)
{
	Vector2d v1 = (a + b) / 2;
	Vector2d v3 = (a + c) / 2;
	if (calcArea({ a, v1, v3 }) > minArea)
	{
		Vector2d v2 = (b + c) / 2;
		s_triangles.push_back({a, b, c});
		subDivide(a, v1, v3, minArea);
		subDivide(v1, b, v2, minArea);
		subDivide(v3, v2, c, minArea);
		subDivide(v1, v2, v3, minArea);
	}
	else
	{
		s_triangles.push_back({ a, b, c });
	}
}

void PlainTriangle::print()
{
	std::cout << "n = " << s_triangles.size() << std::endl;
	for (auto&& tri : s_triangles)
	{
		std::cout << "(" << tri.m_v1.x << ",  " << tri.m_v1.y << "),\t";
		std::cout << "(" << tri.m_v2.x << ",  " << tri.m_v2.y << "),\t";
		std::cout << "(" << tri.m_v3.x << ",  " << tri.m_v3.y << ")\t";
		std::cout << "Area: " << calcArea(tri);
		std::cout << std::endl;
	}
}

double PlainTriangle::calcArea(const PlainTriangle& tri)
{
	double a = (tri.m_v2 - tri.m_v1).size();
	double b = (tri.m_v3 - tri.m_v2).size();
	double c = (tri.m_v1 - tri.m_v3).size();
	double s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
