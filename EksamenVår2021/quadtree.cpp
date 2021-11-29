#include "quadtree.h"

QuadNode::QuadNode(const Rect& rect, QuadNode* parent)
	:rect_(rect), sv_(nullptr), so_(nullptr), no_(nullptr), nv_(nullptr), parent_(parent), max_gameobjects(16)
{
}

QuadNode::~QuadNode()
{
	collapse();
}

void QuadNode::divide()
{
	auto m = rect_.mid();

	auto x = (rect_.a + rect_.b) / 2.0;
	auto y = (rect_.b + rect_.c) / 2.0;
	auto z = (rect_.c + rect_.d) / 2.0;
	auto w = (rect_.d + rect_.a) / 2.0;

	sv_ = new QuadNode({ rect_.a, x, m, w }, this);
	so_ = new QuadNode({ x, rect_.b, y, m }, this);
	no_ = new QuadNode({ m, y, rect_.c, z }, this);
	nv_ = new QuadNode({ w, m, z, rect_.d }, this);

	childnodes_.push_back(sv_);
	childnodes_.push_back(so_);
	childnodes_.push_back(no_);
	childnodes_.push_back(nv_);
}

void QuadNode::collapse()
{
	// TODO(Sten): make some kind of function to collaps when sum
	// of parent node children is <= max_gameobjecs??
	delete sv_;
	delete so_;
	delete no_;
	delete nv_;
}

void QuadNode::print_corners() const
{
	// recursive printing of all corners for all nodes
	std::cout << rect_ << std::endl;
	for (auto node : childnodes_)
		node->print_corners();
}

void QuadNode::print_leaf_corners() const
{
	// since a leaf has no children, simply check for children.
	// divide() populates the childnodes_ vector.
	// manual insertion will fuck this :)
	if (childnodes_.size() == 0)
		std::cout << rect_ << std::endl;

	for (auto node : childnodes_)
		node->print_leaf_corners();
}

void QuadNode::insert_gameobject(GameObject* gameobject)
{
	for (auto node : childnodes_) {
		if (node->rect_.intersect(gameobject->pos)) {
			node->insert_gameobject(gameobject);
		}
	}
	if (childnodes_.empty()) {
		gameobjects_.push_back(gameobject);
	}
}

void QuadNode::printSub(const Vector2d& m)
{
	for (auto node : childnodes_) {
		if (node->rect_.intersect(m)) {
			node->printSub(m);
		}
	}
	if (childnodes_.empty()) {
		for (auto go : gameobjects_) {
			std::cout << *go << std::endl;
		}
	}
}

void QuadNode::printAll() const
{
	for (auto node : childnodes_) {
		node->printAll();
	}
	for (auto go : gameobjects_) {
		std::cout << *go << std::endl;
	}
}

Vector2d Rect::mid()
{
	return (a + c) / 2.0;
}

bool Rect::intersect(const Vector2d& pos)
{
	// inclusive box intersect since the random function populating can be 1.0,
	// and i want them all to succeed. :)
	// But this means gameobjects on boarders will return true for both.
	// Witch is fine since that loop will break;
	if (pos.x >= a.x && pos.x <= b.x
	&&	pos.y >= a.y && pos.y <= d.y)
	{
		return true;
	}
	return false;
}

std::ostream& operator << (std::ostream& out, const Vector2d& v)
{
	out << "(" << v.x << ", " << v.y << ")";
	return out;
}

std::ostream& operator << (std::ostream& out, const Rect& r)
{
	out << r.a << ' ' << r.b << ' ' << r.c << ' ' << r.d;
	return out;
}

std::ostream& operator<<(std::ostream& out, const GameObject& r)
{
	out << r.name << ' ' << r.pos;
	return out;
}
