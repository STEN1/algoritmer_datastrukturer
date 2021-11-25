#include <iostream>

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
	if (m_right)
		m_right->stigende();
	std::cout << m_data << std::endl;
	if (m_left)
		m_left->stigende();
}

void BinaryNode::avtakende() const
{
	if (m_left)
		m_left->avtakende();
	std::cout << m_data << std::endl;
	if (m_right)
		m_right->avtakende();
}


int main()
{
	BinaryNode root(14);
	root.insert(33);
	root.insert(12);
	root.insert(4);
	root.insert(7);
	root.insert(19);
	root.insert(29);
	root.insert(11);
	root.insert(21);
	root.insert(17);

	std::cout << "Stigende:\n";
	root.stigende();

	std::cout << "avtakende:\n";
	root.avtakende();
}