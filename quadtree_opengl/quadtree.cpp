#include "quadtree.h"

#include "sprite.h"

QuadNode::QuadNode(const Rect& rect, Shader* shader, QuadNode* parent)
	:rect_(rect), sv_(nullptr), so_(nullptr), no_(nullptr), nv_(nullptr), parent_(parent), max_gameobjects(4),
	sprite(shader, "assets/Rect.png", rect)
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

	sv_ = new QuadNode({ rect_.a, x, m, w }, sprite.get_shader(), this);
	so_ = new QuadNode({ x, rect_.b, y, m }, sprite.get_shader(), this);
	no_ = new QuadNode({ m, y, rect_.c, z }, sprite.get_shader(), this);
	nv_ = new QuadNode({ w, m, z, rect_.d }, sprite.get_shader(), this);

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

void QuadNode::render_world()
{
	sprite.Render();
	for (auto node : childnodes_)
	{
		node->render_world();
	}
}

void QuadNode::render_gameobjects()
{
	for (auto node : childnodes_)
	{
		node->render_gameobjects();
	}
	for (auto& gameobject : gameobjects_)
	{
		gameobject->sprite.Render();
	}
}

std::pair<QuadNode*, bool> QuadNode::insert_gameobject(GameObject* gameobject)
{
	// drop the gameobject if it is out of bounds.
	if (!rect_.intersect(gameobject->pos))
	{
		return {nullptr, false};
	}
	// if this node has child nodes -> send gameobject to correct child node
	for (auto node : childnodes_)
	{
		if (node->rect_.intersect(gameobject->pos))
		{
			return node->insert_gameobject(gameobject);
		}
	}
	// if this node has to many gameobject -> subdevide and send all stored objects down
	// to the correct child node. send gameobject to this function again to get the correct node.
	// dividing again if all nodes are again in one of the child nodes.
	if (gameobjects_.size() == max_gameobjects)
	{
		divide();
		for (const auto& gameobject : gameobjects_)
		{
			for (auto node : childnodes_)
			{
				if (node->rect_.intersect(gameobject->pos))
				{
					node->gameobjects_.push_back(gameobject);
					break;
				}
			}
		}
		gameobjects_.clear();
		return insert_gameobject(gameobject);
	}
	// finally pushing the gameobject
	else if (gameobjects_.size() < max_gameobjects)
	{
		gameobjects_.push_back(gameobject);
		return { this, true };
	}
}



