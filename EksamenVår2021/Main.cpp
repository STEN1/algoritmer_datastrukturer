#include <iostream>
#include <queue>
#include "quadtree.h"

class BinaryNode
{
public:
	BinaryNode(double data = 0.0);
	void insert(double data);
	void stigende() const;
	void avtakende() const;
	double sum() const;

private:
	double m_data;
	BinaryNode* m_left;
	BinaryNode* m_right;
};

BinaryNode::BinaryNode(double data)
	: m_data{data}, m_left{nullptr}, m_right{nullptr} {}

void BinaryNode::insert(double data)
{
	if (data < m_data) {
		if (m_left)
			m_left->insert(data);
		else
			m_left = new BinaryNode(data);
	}
	else if (data > m_data) {
		if (m_right)
			m_right->insert(data);
		else
			m_right = new BinaryNode(data);
	}
}

void BinaryNode::stigende() const
{
	if (m_left) m_left->stigende();
	std::cout << m_data << std::endl;
	if (m_right) m_right->stigende();
}

void BinaryNode::avtakende() const
{
	if (m_right) m_right->avtakende();
	std::cout << m_data << std::endl;
	if (m_left) m_left->avtakende();
}

double BinaryNode::sum() const
{
	double sum{ m_data };
	if (m_left) sum += m_left->sum();
	if (m_right) sum += m_right->sum();
	return sum;
}

int main()
{
	// 1d
	auto data1d = { 2.71828, 1.732, 1.414, 3.1316, 9.81 };
	std::priority_queue<double> maxHeap;
	for (auto d : data1d)
		maxHeap.push(d);
	maxHeap.pop();
	std::cout << maxHeap.top();

	std::cout << "\n\n\n";
	// 2
	auto data2 = { 1.732, 1.414, 3.1316, 9.81 };
	BinaryNode binarytree(2.71828);
	for (auto d : data2)
		binarytree.insert(d);
	std::cout << "stigende:\n";
	binarytree.stigende();
	std::cout << "avtakende:\n";
	binarytree.avtakende();
	std::cout << "sum: " << binarytree.sum() << std::endl; 
	// 3
	Rect sceneSize = {
		{-4.0, -4.0},
		{4.0, -4.0},
		{4.0, 4.0},
		{-4.0, 4.0}
	};
	QuadNode scene{ sceneSize };
	scene.divide();
	scene.no()->divide();
	scene.no()->so()->divide();
	std::vector<GameObject> gameobjects = {
		{"Sten", {-2.0, -2.0}},
		{"Adrian", {1.0, 3.0}},
		{"Espen", {3.5, 1.5}},
		{"Eddy", {3.2, 1.2}},
		{"Erik", {3.4, 1.4}},
	};
	for (auto& go : gameobjects)
		scene.insert_gameobject(&go);
	std::cout << "printSub:\n";
	scene.printSub({ -2.0, -2.0 });
	std::cout << "printAll:\n";
	scene.printAll();
}