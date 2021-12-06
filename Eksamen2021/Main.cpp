#include <iostream>
#include <vector>
#include <algorithm>
#include "Quadtree.h"

class BinaryNode
{
private:
	char m_data;
	int m_frekvens;
	BinaryNode* m_left;
	BinaryNode* m_right;
	void GetNodes(std::vector<BinaryNode*>& nodes);
public:
	explicit BinaryNode(char data) : m_data{ data }, m_left{ nullptr },
		m_right{ nullptr }, m_frekvens{ 1 } { }
	void insert(char data);
	void print() const;
	void printfrekvens();
};

void BinaryNode::insert(char data)
{
	if (data == m_data)
	{
		m_frekvens++;
		return;
	}
	if (data < m_data)
	{
		if (m_left)
			m_left->insert(data);
		else
			m_left = new BinaryNode(data);
	}
	else if (data > m_data)
	{
		if (m_right)
			m_right->insert(data);
		else
			m_right = new BinaryNode(data);
	}
}

void BinaryNode::print() const
{
	if (m_left) m_left->print();
	std::cout << "data: " << m_data << " frekvens: " << m_frekvens << std::endl;
	if (m_right) m_right->print();
}

void BinaryNode::GetNodes(std::vector<BinaryNode*>& nodes)
{
	nodes.push_back(this);
	if (m_left) m_left->GetNodes(nodes);
	if (m_right) m_right->GetNodes(nodes);
}

void BinaryNode::printfrekvens()
{
	std::vector<BinaryNode*> nodes;
	GetNodes(nodes);
	auto comp = [](BinaryNode* l, BinaryNode* r) { return l->m_frekvens < r->m_frekvens; };
	std::sort(nodes.begin(), nodes.end(), comp);
	for (auto node : nodes)
		std::cout << "data: " << node->m_data << " frekvens: " << node->m_frekvens << std::endl;
}

int hash(int key) { return key % 7; }

int dobbelthash(int key) { return 1 + key % 6; }

int main()
{
	// 2
	std::string s{ "det er enklere å løse et algoritmisk problem enn et demokratisk problem" };
	BinaryNode btree('d');
	for (size_t i = 1; i < s.size(); i++)
		btree.insert(s[i]);
	btree.print();
	std::cout << std::endl;
	//print frekvens
	std::cout << "etter frekvens...\n";
	btree.printfrekvens();

	// 4
	Rect sceneSize = {
	{-2.0, -2.0},
	{2.0, -2.0},
	{2.0, 4.0},
	{-2.0, 2.0}
	};
	QuadNode scene1{ sceneSize };
	for (size_t i = 0; i < 20; i++)
	{
		Vector2d pos = {
			(((double)rand() / (double)RAND_MAX) - 0.5) * 4.0,
			(((double)rand() / (double)RAND_MAX) - 0.5) * 4.0
		};
		scene1.insert_gameobject(new GameObject("", pos));
	}
	for (size_t i = 0; i < 20; i++)
	{
		Vector2d pos = {
			(((double)rand() / (double)RAND_MAX)) * 0.2,
			(((double)rand() / (double)RAND_MAX)) * 0.2
		};
		scene1.insert_gameobject(new GameObject("", pos));
	}
	QuadNode scene2{ sceneSize };
	for (size_t i = 0; i < 20; i++)
	{
		Vector2d pos = {
			(((double)rand() / (double)RAND_MAX) - 0.5) * 4.0,
			(((double)rand() / (double)RAND_MAX) - 0.5) * 4.0
		};
		scene2.insert_gameobject2(new GameObject("", pos));
	}
	for (size_t i = 0; i < 20; i++)
	{
		Vector2d pos = {
			(((double)rand() / (double)RAND_MAX)) * 0.2,
			(((double)rand() / (double)RAND_MAX)) * 0.2
		};
		scene2.insert_gameobject2(new GameObject("", pos));
	}
	scene1.printAll();
	scene2.printAll();

		// 7, 8, 13, 4, 3, 11, 9.
	
	int h = hash(11);
	std::cout << h << std::endl;
	while (h != 5)
	{
		h += dobbelthash(11);
		h = h % 7;
		std::cout << h << std::endl;
	}
}

/*
* 
Oppgave 10Oppgave 3a)
(Oppgave 3a-b teller 15%) En urettet graf består av nodene 
{ A, B, C, D, E, F, G, H } og kantene
{ AB(2), AC(3), AD(2), AE(4), AF(4), BC(1),
	CD(2), DE(2), EF(3), EG(1), EH(2), FH(1), GH(2) }.
Tegn og forklar hvordan du finner et minimum spenntre
ved å bruke Kruskal's algoritme.
*/