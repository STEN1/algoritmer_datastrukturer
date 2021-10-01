#pragma once
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include "gameobject.h"
#include "rect.h"



class QuadNode 
{
public:
	QuadNode() = delete;
	QuadNode(const Rect& rect, Shader* shader, QuadNode* parent = nullptr);
	~QuadNode();

	void divide();
	void collapse();

	void print_corners() const;
	void print_leaf_corners() const;
	void render_world();
	void render_gameobjects();
	std::pair<QuadNode*, bool> insert_gameobject(GameObject* gameobject);

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
	Sprite sprite;
};