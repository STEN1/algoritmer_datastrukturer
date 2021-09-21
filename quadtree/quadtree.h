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
std::ostream& operator << (std::ostream& out, const Vector2d& v);
struct Rect
{
	Vector2d a, b, c, d;
	Vector2d mid();
};
std::ostream& operator << (std::ostream& out, const Rect& r);

class QuadNode 
{
public:
	QuadNode() = delete;
	QuadNode(const Rect& rect, QuadNode* parent = nullptr);
	~QuadNode();

	void divide();
	void collapse();

	void print() const;

	QuadNode* a() { return a_; }
	QuadNode* b() { return b_; }
	QuadNode* c() { return c_; }
	QuadNode* d() { return d_; }

private:
	Rect rect_;
	QuadNode* a_,* b_,* c_,* d_,* parent_;
};