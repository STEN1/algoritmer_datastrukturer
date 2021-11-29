#pragma once
#include <cmath>
#include <iostream>
#include <string>
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
std::ostream& operator << (std::ostream& out, const Vector2d& v);
struct Rect
{
	Vector2d a, b, c, d;
	Vector2d mid();
	bool intersect(const Vector2d& pos);
};
std::ostream& operator << (std::ostream& out, const Rect& r);
struct GameObject
{
	Vector2d pos;
	std::string name;

	GameObject() = delete;
	GameObject(const std::string& name, const Vector2d& pos) : name(name), pos(pos) {}
};
std::ostream& operator << (std::ostream& out, const GameObject& r);

class QuadNode 
{
public:
	QuadNode() = delete;
	QuadNode(const Rect& rect, QuadNode* parent = nullptr);
	~QuadNode();

	void divide();
	void collapse();

	void print_corners() const;
	void print_leaf_corners() const;
	void insert_gameobject(GameObject* gameobject);
	void printSub(const Vector2d& m);
	void printAll() const;

	QuadNode* sv() { return sv_; }
	QuadNode* so() { return so_; }
	QuadNode* no() { return no_; }
	QuadNode* nv() { return nv_; }

private:
	Rect rect_;
	QuadNode* sv_,* so_,* no_,* nv_,* parent_;
	std::vector<GameObject*> gameobjects_;
	uint8_t max_gameobjects;
	std::vector<QuadNode*> childnodes_;
};