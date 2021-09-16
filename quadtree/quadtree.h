#pragma once
#include <cmath>
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

std::ostream& operator << (std::ostream& out, const Vector2d& v)
{
	out << "(" << v.x << ", " << v.y << ")";
	return out;
}

struct Rect
{
	Vector2d a, b, c, d;
};

std::ostream& operator << (std::ostream& out, const Rect& r)
{
	out << r.a << ' ' << r.b << ' ' << r.c << ' ' << r.d;
	return out;
}

template<typename T>
concept NodeType = requires (T data)
{
	std::cout << data;
};

template<NodeType T>
class QuadNode 
{
public:
	QuadNode() = delete;
	QuadNode(const T& data, QuadNode* a = nullptr, QuadNode* b = nullptr, QuadNode* c = nullptr, QuadNode* d = nullptr)
		:data_(data), a_(a), b_(b), c_(c), d_(d){}
private:
	T data_;
	QuadNode* a_,* b_,* c_,* d_;
};