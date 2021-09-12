#include "plainrectangle.h"

#include <iostream>

std::vector<PlainRectangle> PlainRectangle::s_rectangles;

PlainRectangle::PlainRectangle(const Vector2d& v1, const Vector2d& v2, const Vector2d& v3, const Vector2d& v4)
	:m_v1(v1)
	,m_v2(v2)
	,m_v3(v3)
	,m_v4(v4)
{
}

void PlainRectangle::subDivide(const Vector2d& a, const Vector2d& b, const Vector2d& c, const Vector2d& d, uint32_t n)
{
	if (n > 0)
	{
		Vector2d v1 = (a + b) / 2;
		Vector2d v2 = (b + c) / 2;
		Vector2d v3 = (c + d) / 2;
		Vector2d v4 = (d + a) / 2;
		Vector2d m = (a + c) / 2;
		s_rectangles.push_back({a, b, c, d});
		subDivide(a, v1, m, v4, n - 1);
		subDivide(v1, b, v2, m, n - 1);
		subDivide(m, v2, c, v3, n - 1);
		subDivide(v4, m, v3, d, n - 1);
	}
	else
	{
		s_rectangles.push_back({ a, b, c, d });
	}
}

void PlainRectangle::print()
{
	std::cout << "n = " << s_rectangles.size() << std::endl;
	for (auto&& rect : s_rectangles)
	{
		std::cout << "(" << rect.m_v1.x << ",  " << rect.m_v1.y << "),\t";
		std::cout << "(" << rect.m_v2.x << ",  " << rect.m_v2.y << "),\t";
		std::cout << "(" << rect.m_v3.x << ",  " << rect.m_v3.y << "),\t";
		std::cout << "(" << rect.m_v4.x << ", " << rect.m_v4.y << ")  \t";
		std::cout << "Area: " << calcArea(rect);
		std::cout << std::endl;
	}
}

double PlainRectangle::calcArea(const PlainRectangle& rect)
{
	return (rect.m_v2.x - rect.m_v1.x) * (rect.m_v3.y - rect.m_v2.y);
}
