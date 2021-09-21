#include "quadtree.h"

QuadNode::QuadNode(const Rect& rect, QuadNode* parent)
	:rect_(rect), a_(nullptr), b_(nullptr), c_(nullptr), d_(nullptr), parent_(parent)
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


	a_ = new QuadNode({ rect_.a, x, m, w }, this);
	b_ = new QuadNode({ x, rect_.b, y, m }, this);
	c_ = new QuadNode({ m, y, rect_.c, z }, this);
	d_ = new QuadNode({ w, m, z, rect_.d }, this);
}

void QuadNode::collapse()
{
	delete a_;
	delete b_;
	delete c_;
	delete d_;
}

void QuadNode::print() const
{
	std::cout << rect_ << std::endl;
	if (a_)
		a_->print();
	if (b_)
		b_->print();
	if (c_)
		c_->print();
	if (d_)
		d_->print();
}

Vector2d Rect::mid()
{
	return (a + c) / 2.0;
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