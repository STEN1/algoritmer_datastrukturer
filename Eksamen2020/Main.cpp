#include <iostream>
#include <queue>

class BinaryNode {
public:
	BinaryNode(int data = 0.0);
	void insert(int data);
	void stigende() const;
	void avtakende() const;
private:
	int m_data;
	BinaryNode* m_left;
	BinaryNode* m_right;
};

BinaryNode::BinaryNode(int data)
	: m_data{ data }, m_left{ nullptr }, m_right{ nullptr } { }

void BinaryNode::insert(int data) {
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
	std::cout << m_data << ' ';
	if (m_right) m_right->stigende();
}
void BinaryNode::avtakende() const
{
	if (m_right) m_right->avtakende();
	std::cout << m_data << ' ';
	if (m_left) m_left->avtakende();
}

struct Node;
struct Edge
{
	Node* m_fra;
	Node* m_til;
	double m_vekt;
	Edge();
	Edge(Node* fra, Node* til);
};
Edge::Edge() : m_fra{nullptr}, m_til{nullptr}, m_vekt{0.0} {}
Edge::Edge(Node* fra, Node* til) : m_fra{fra}, m_til{til}, m_vekt{1.0} {}

struct Node
{
	Node() = default;
	Node(char navn) : m_navn{navn} {}
	char m_navn;
	std::vector<Edge*> m_kanter;
	void push_edge(Edge* kant) { m_kanter.push_back(kant); }
};

struct Graph
{
	std::vector<Node*> m_noder;
	Graph();
	Node* find_node(char navn);
	void make_edges(char x, char y);
	void make_all_edges();
	void print() const;
};

Graph::Graph()
{
	for (char c = 'A'; c <= 'H'; c++)
		m_noder.emplace_back(new Node(c));
	m_noder.emplace_back(new Node('S'));
	m_noder.emplace_back(new Node('M'));
}

Node* Graph::find_node(char navn)
{
	for (Node* node : m_noder)
		if (node->m_navn == navn) return node;
	return nullptr;
}

void Graph::make_edges(char x, char y)
{
	Node* nodeX = find_node(x);
	Node* nodeY = find_node(y);
	if (nodeX && nodeY)
	{
		Edge* xy = new Edge(nodeX, nodeY);
		Edge* yx = new Edge(nodeY, nodeX);
		nodeX->push_edge(xy);
		nodeY->push_edge(yx);
	}
}

void Graph::make_all_edges()
{
	// ac ab ce em ef fg gh gd bs sd
	make_edges('A', 'C');
	make_edges('A', 'B');
	make_edges('C', 'E');
	make_edges('E', 'M');
	make_edges('E', 'F');
	make_edges('F', 'G');
	make_edges('G', 'H');
	make_edges('G', 'D');
	make_edges('B', 'S');
	make_edges('S', 'D');
}

void Graph::print() const
{
	for (Node* node : m_noder)
	{
		std::cout << "Node navn: " << node->m_navn << " Kanter: ";
		for (Edge* edge : node->m_kanter)
			std::cout << "(" << edge->m_fra->m_navn << ", " << edge->m_til->m_navn << ", vekt: " << edge->m_vekt << ") ";
		std::cout << std::endl;
	}
}


int main() 
{
	// 2
	BinaryNode btree(14);
	int data[] = {14, 33, 12, 4, 7, 19, 29, 11};
	for (int i = 1; i < sizeof(data)/sizeof(int); i++)
		btree.insert(data[i]);
	std::cout << "Skriver avtagende: ";
	btree.avtakende();
	std::cout << std::endl;
	std::cout << "Skriver stigende: ";
	btree.stigende();
	std::cout << std::endl;

	// 3a
	// tallene er sorter med flettesortering (mergesort).
	// tallene blir satt inn i større og større arrayer på størrelse 2^n.
	// som da flettes sammen til sorterte subarrayer. helt til man har et sortert array

	// 3b
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
	for (int i : data)
		minHeap.push(i);
	std::cout << "Min heap: ";
	while (!minHeap.empty())
	{
		std::cout << minHeap.top() << ' ';
		minHeap.pop();
	}
	std::cout << std::endl;

	// 4
	Graph graph;
	graph.make_all_edges();
	graph.print();
}


