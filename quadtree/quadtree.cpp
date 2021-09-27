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
	delete sv_;
	delete so_;
	delete no_;
	delete nv_;
}

void QuadNode::print_corners() const
{
	std::cout << rect_ << std::endl;
	if (sv_)
		sv_->print_corners();
	if (so_)
		so_->print_corners();
	if (no_)
		no_->print_corners();
	if (nv_)
		nv_->print_corners();
}

std::pair<QuadNode*, bool> QuadNode::insert_gameobject(const GameObject& gameobject)
{
	if (!rect_.intersect(gameobject.pos))
	{
		return {nullptr, false};
	}
	for (auto node : childnodes_)
	{
		if (node->rect_.intersect(gameobject.pos))
		{
			return node->insert_gameobject(gameobject);
		}
	}
	if (gameobjects_.size() == max_gameobjects)
	{
		divide();
		for (auto iter = gameobjects_.begin(); iter != gameobjects_.end(); iter++)
		{
			for (auto node : childnodes_)
			{
				if (node->rect_.intersect((*iter).pos))
				{
					node->gameobjects_.push_back(*iter);
					break;
				}
			}
		}
		gameobjects_.clear();
		return insert_gameobject(gameobject);
	}
	else if (gameobjects_.size() < max_gameobjects)
	{
		gameobjects_.push_back(gameobject);
		return { this, true };
	}
}

Vector2d Rect::mid()
{
	return (a + c) / 2.0;
}

bool Rect::intersect(const Vector2d& pos)
{
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
