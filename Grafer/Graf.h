#pragma once
#include <vector>

struct Kant;
struct Node
{
	char navn;
	bool besøkt{ false };
	std::vector<Kant> kanter;
	Node(char navn) : navn{ navn } {}
};

struct Kant
{
	float vekt;
	Node* tilnode;
	Kant(Node* tilnode, float vekt) : tilnode{ tilnode }, vekt{ vekt } {}
};

struct Vei
{
	std::vector<Kant> kanter;
	float vei_kostnad() const 
	{
		float kost{};
		for (auto& kant : kanter)
		{
			kost += kant.vekt;
		}
		return kost;
	}
	operator float () const { return vei_kostnad(); }
};

struct Graf
{
	std::vector<Node*> noder;
	void sett_inn_node(char navn)
	{
		noder.emplace_back(new Node(navn));
	}
	void sett_inn_kant(char franavn, char tilnavn, float vekt)
	{
		Node* franode{ nullptr };
		Node* tilnode{ nullptr };
		for (auto node : noder)
		{
			if (node->navn == franavn)
				franode = node;
			if (node->navn == tilnavn)
				tilnode = node;
		}
		if (franode && tilnode)
		{
			franode->kanter.emplace_back(tilnode, vekt);
		}
	}
	void test()
	{
		sett_inn_node('A');
		sett_inn_node('B');
		sett_inn_node('C');
		sett_inn_node('D');
		sett_inn_node('E');
		sett_inn_node('F');
		sett_inn_node('G');

		sett_inn_kant('A', 'B', 2.f);
	}
};
